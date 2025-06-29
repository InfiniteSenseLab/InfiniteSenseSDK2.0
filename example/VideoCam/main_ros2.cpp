#include "infinite_sense.h"
#include "video_cam.h"

#include "rclcpp/rclcpp.hpp"

#include <image_transport/image_transport.hpp>
#include <cv_bridge/cv_bridge.h>

#include <sensor_msgs/msg/imu.hpp>

// 继承自 rclcpp::Nod
class CamDriver final : public rclcpp::Node {
 public:
  CamDriver()
      : Node("ros2_cam_driver"), node_handle_(std::shared_ptr<CamDriver>(this, [](auto *) {})), transport_(node_handle_) {
    // 相机名称，注意和video_cam.cpp 中的相机名称保持一致
    std::string camera_name_1 = "video_cam";
    // IMU 设备名称，自定义即可
    const std::string imu_name = "imu_1";
    // 使用串口设备进行同步，这里可以选择不同的设备
    synchronizer_.SetUsbLink("/dev/ttyACM0", 921600);
    // synchronizer_.SetNetLink("192.168.1.188", 8888);
    // 构建 VideoCam 类
    const auto video_cam = std::make_shared<infinite_sense::VideoCam>();
    // 重要！！！注册相机名称video_cam， 并且绑定 CAM_1 接口，也就是 video_cam对应的设备必须要接到 CAM_1
    video_cam->SetParams({{camera_name_1, infinite_sense::CAM_1}
    });
    // 同步类设置添加相机类 
    synchronizer_.UseSensor(video_cam);

    // 逐个调用开始函数 
    synchronizer_.Start();

    // IMU 和 图像信息的发布函数 
    imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>(imu_name, 10);
    img1_pub_ = transport_.advertise(camera_name_1, 10);
    // SDK 获取IMU和图像信息之后的回调函数 
    {
      using namespace std::placeholders;
      infinite_sense::Messenger::GetInstance().SubStruct(imu_name, std::bind(&CamDriver::ImuCallback, this, _1, _2));
      infinite_sense::Messenger::GetInstance().SubStruct(camera_name_1,
                                                         std::bind(&CamDriver::ImageCallback1, this, _1, _2));
    }
  }

  // SDK 获取IMU信息后的回调函数 
  void ImuCallback(const void *msg, size_t) const {
    // 按照ROS2的格式发布的IMU数据
    const auto *imu_data = static_cast<const infinite_sense::ImuData *>(msg);
    sensor_msgs::msg::Imu imu_msg;
    // 得到的时间单位us,需要转换为ms
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

  // SDK 获取图像信息后的回调函数 
  void ImageCallback1(const void *msg, size_t) const {
    // 原始的图像数据
    const auto *cam_data = static_cast<const infinite_sense::CamData *>(msg);
    std_msgs::msg::Header header;
    // 得到的时间单位us,需要转换为ms
    header.stamp = rclcpp::Time(cam_data->time_stamp_us * 1000);
    header.frame_id = "map";
    // 构造opencv图像，这里是彩色图片因此是 CV_8UC3 和  bgr8
    const cv::Mat image_mat(cam_data->image.rows, cam_data->image.cols, CV_8UC3, cam_data->image.data);
    const sensor_msgs::msg::Image::SharedPtr image_msg = cv_bridge::CvImage(header, "bgr8", image_mat).toImageMsg();
    img1_pub_.publish(image_msg);
  }


 private:
  infinite_sense::Synchronizer synchronizer_;
  SharedPtr node_handle_;
  image_transport::ImageTransport transport_;
  image_transport::Publisher img1_pub_,img2_pub_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
};

// main 函数 
int main(const int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  // 构造 CamDriver 类，用于读取相机、IMU等信息
  rclcpp::spin(std::make_shared<CamDriver>());
  return 0;
}
