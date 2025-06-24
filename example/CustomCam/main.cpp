#include "infinite_sense.h"
#include "cus_cam.h"
using namespace infinite_sense;
void ImuCallback(const void* msg, size_t) {
  const auto* imu_data = static_cast<const ImuData*>(msg);
  // 处理IMU数据
}
void ImageCallback(const void* msg, size_t) {
  const auto* cam_data = static_cast<const CamData*>(msg);
  // 处理图像数据
}
int main() {
  // 1.创建同步器
  Synchronizer synchronizer;
  // synchronizer.SetUsbLink("/dev/ttyACM0", 460800);
  synchronizer.SetNetLink("192.168.1.188", 8888);
  // 2.配置同步接口
  auto mv_cam = std::make_shared<CustomCam>();
  mv_cam->SetParams({
      {"cam_1", CAM_1},
      {"cam_2", CAM_2},
  });
  synchronizer.UseSensor(mv_cam);

  // 3.开启同步
  synchronizer.Start();

  // 4.接收数据
  Messenger::GetInstance().SubStruct("imu_1", ImuCallback);
  Messenger::GetInstance().SubStruct("cam_1", ImageCallback);
  // 5.停止同步
  synchronizer.Stop();
  return 0;
}