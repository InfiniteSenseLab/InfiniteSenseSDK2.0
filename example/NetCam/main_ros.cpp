#include "infinite_sense.h"
#include "mv_cam.h"

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/Imu.h>

using namespace infinite_sense;
inline ros::Time CreateRosTimestamp(const uint64_t mico_sec) {
  uint32_t nsec_per_second = 1e9;
  auto u64 = mico_sec * 1000;
  uint32_t sec = u64 / nsec_per_second;
  uint32_t nsec = u64 - (sec * nsec_per_second);
  return {sec, nsec};
}

class CamDriver {
 public:
  CamDriver(ros::NodeHandle &nh) : node_(nh), it_(node_), camera_name_("cam_1"), imu_name_("imu_1") {}
  void ImuCallback(const void *msg, size_t) {
    const auto *imu_data = static_cast<const ImuData *>(msg);
    sensor_msgs::Imu imu_msg_data;
    imu_msg_data.header.frame_id = "map";
    imu_msg_data.header.stamp = CreateRosTimestamp(imu_data->time_stamp_us);

    imu_msg_data.angular_velocity.x = imu_data->g[0];
    imu_msg_data.angular_velocity.y = imu_data->g[1];
    imu_msg_data.angular_velocity.z = imu_data->g[2];

    imu_msg_data.linear_acceleration.x = imu_data->a[0];
    imu_msg_data.linear_acceleration.y = imu_data->a[1];
    imu_msg_data.linear_acceleration.z = imu_data->a[2];

    imu_msg_data.orientation.w = imu_data->q[0];
    imu_msg_data.orientation.x = imu_data->q[1];
    imu_msg_data.orientation.y = imu_data->q[2];
    imu_msg_data.orientation.z = imu_data->q[3];
    imu_pub_.publish(imu_msg_data);
  }

  // 自定义回调函数
  void ImageCallback(const void *msg, size_t) {
    const auto *cam_data = static_cast<const CamData *>(msg);
    const cv::Mat image_mat(cam_data->image.rows, cam_data->image.cols, CV_8UC1, cam_data->image.data);
    sensor_msgs::ImagePtr image_msg =
        // mono8:灰度类型,bgr8:彩图，具体需要根据相机类型进行修改
        cv_bridge::CvImage(std_msgs::Header(), "mono8", image_mat).toImageMsg();
    image_msg->header.stamp = CreateRosTimestamp(cam_data->time_stamp_us);
    image_pub_.publish(image_msg);
  }
  void Init() {
    synchronizer_.SetUsbLink("/dev/ttyACM0", 921600);
    mv_cam_ = std::make_shared<MvCam>();
    mv_cam_->SetParams({{"cam_1", CAM_1}});
    synchronizer_.UseSensor(mv_cam_);
    imu_pub_ = node_.advertise<sensor_msgs::Imu>(imu_name_, 1000);
    image_pub_ = it_.advertise(camera_name_, 30);
    synchronizer_.Start();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    Messenger::GetInstance().SubStruct(
        "imu_1", std::bind(&CamDriver::ImuCallback, this, std::placeholders::_1, std::placeholders::_2));
    Messenger::GetInstance().SubStruct(
        "cam_1", std::bind(&CamDriver::ImageCallback, this, std::placeholders::_1, std::placeholders::_2));
  }

  void Run() {
    ros::Rate loop_rate(1000);
    while (ros::ok()) {
      ros::spinOnce();
      loop_rate.sleep();
    }
    synchronizer_.Stop();
  }

 private:
  ros::NodeHandle &node_;
  ros::Publisher imu_pub_;
  image_transport::ImageTransport it_;
  image_transport::Publisher image_pub_;
  std::shared_ptr<MvCam> mv_cam_;
  Synchronizer synchronizer_;
  std::string camera_name_;
  std::string imu_name_;
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "ros_demo", ros::init_options::NoSigintHandler);
  ros::NodeHandle node;
  CamDriver demo_node(node);
  demo_node.Init();
  demo_node.Run();

  return 0;
}