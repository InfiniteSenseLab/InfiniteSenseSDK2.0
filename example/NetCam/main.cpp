// 加入SDK头文件
#include "infinite_sense.h"
// 加入工业相机头文件
#include "mv_cam.h"
using namespace infinite_sense;
// 自定义回调函数
void ImuCallback(const void *msg, size_t) {
  const auto *imu_data = static_cast<const ImuData *>(msg);
  LOG(INFO) << imu_data->time_stamp_us << " " << "Accel: " << imu_data->a[0] << " " << imu_data->a[1] << " "
            << imu_data->a[2] << " Gyro: " << imu_data->g[0] << " " << imu_data->g[1] << " " << imu_data->g[2]
            << " Temp: " << imu_data->temperature;
  // 处理IMU数据
}

// 自定义回调函数
void ImageCallback(const void *msg, size_t) {
  const auto *cam_data = static_cast<const CamData *>(msg);
  // 处理图像数据
}

int main() {
  // 1.创建同步器
  Synchronizer synchronizer;
  // synchronizer.SetUsbLink("/dev/ttyACM0", 921600);
  synchronizer.SetNetLink("192.168.1.188", 8888);
  // 2.配置同步接口
  auto mv_cam = std::make_shared<MvCam>();
  mv_cam->SetParams({{"cam_1", CAM_1}});
  synchronizer.UseSensor(mv_cam);

  // 3.开启同步
  synchronizer.Start();

  // 4.接收数据
  Messenger::GetInstance().SubStruct("imu_1", ImuCallback);
  Messenger::GetInstance().SubStruct("cam_1", ImageCallback);
  // 阻塞线程
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  // 5.停止同步
  synchronizer.Stop();
  return 0;
}
