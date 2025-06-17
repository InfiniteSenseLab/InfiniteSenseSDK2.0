#include "infinite_sense.h"
#include "mv_cam.h"

#include "rclcpp/rclcpp.hpp"

#include <image_transport/image_transport.hpp>
#include <cv_bridge/cv_bridge.h>

#include <sensor_msgs/msg/imu.hpp>

class CamDriver final : public rclcpp::Node {
 public:
  CamDriver()
      : Node("gige_driver"), node_handle_(std::shared_ptr<CamDriver>(this, [](auto *) {})), transport_(node_handle_) {
    std::string camera_name = "cam_1";
    const std::string imu_name = "imu_1";
    // synchronizer_.SetUsbLink("/dev/ttyACM0", 921600);
    synchronizer_.SetNetLink("192.168.1.188", 8888);
    const auto mv_cam = std::make_shared<infinite_sense::MvCam>();
    mv_cam->SetParams({{camera_name, infinite_sense::CAM_1}});
    synchronizer_.UseSensor(mv_cam);
    synchronizer_.Start();
    imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>(imu_name, 10);
    img_pub_ = transport_.advertise(camera_name, 10);
    {
      using namespace std::placeholders;
      infinite_sense::Messenger::GetInstance().SubStruct(imu_name, std::bind(&CamDriver::ImuCallback, this, _1, _2));
      infinite_sense::Messenger::GetInstance().SubStruct(camera_name,
                                                         std::bind(&CamDriver::ImageCallback, this, _1, _2));
    }
  }

  void ImuCallback(const void *msg, size_t) const {
    const auto *imu_data = static_cast<const infinite_sense::ImuData *>(msg);
    sensor_msgs::msg::Imu imu_msg;
    imu_msg.header.stamp = rclcpp::Time(imu_data->time_stamp_us * 1000);
    imu_msg.header.frame_id = "map";
    imu_msg.linear_acceleration.x = imu_data->a[0];
    imu_msg.linear_acceleration.y = imu_data->a[1];
    imu_msg.linear_acceleration.z = imu_data->a[2];
    imu_msg.angular_velocity.x = imu_data->g[0];
    imu_msg.angular_velocity.y = imu_data->g[1];
    imu_msg.angular_velocity.z = imu_data->g[2];
    imu_msg.orientation.w = imu_data->q[0];
    imu_msg.orientation.x = imu_data->q[1];
    imu_msg.orientation.y = imu_data->q[2];
    imu_msg.orientation.z = imu_data->q[3];
    imu_pub_->publish(imu_msg);
  }

  void ImageCallback(const void *msg, size_t) const {
    const auto *cam_data = static_cast<const infinite_sense::CamData *>(msg);
    std_msgs::msg::Header header;
    header.stamp = rclcpp::Time(cam_data->time_stamp_us * 1000);
    header.frame_id = "map";
    const cv::Mat image_mat(cam_data->image.rows, cam_data->image.cols, CV_8UC1, cam_data->image.data);
    const sensor_msgs::msg::Image::SharedPtr image_msg = cv_bridge::CvImage(header, "mono8", image_mat).toImageMsg();
    img_pub_.publish(image_msg);
  }

 private:
  infinite_sense::Synchronizer synchronizer_;
  SharedPtr node_handle_;
  image_transport::ImageTransport transport_;
  image_transport::Publisher img_pub_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
};

int main(const int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CamDriver>());
  return 0;
}
