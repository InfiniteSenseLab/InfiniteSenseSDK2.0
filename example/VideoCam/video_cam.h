#pragma once
#include "infinite_sense.h"
#include <opencv2/opencv.hpp>
#include <atomic>
#include <thread>
#include <vector>
#include <mutex>
namespace infinite_sense {
// 继承自 Sensor 类，会自动调用初始化，开始，停止等函数 
class VideoCam final : public Sensor {
 public:
  ~VideoCam() override;

  bool Initialization() override; // 相机初始化函数
  void Stop() override; // 相机停止采集函数
  void Start() override;// 相机参数函数

 private:
  // 具体读取相机的实现
  void Receive(void* handle, const std::string&) override;
  // opencv 读取 video 设备的函数
  cv::VideoCapture cap_;
  // 是否初始化的标识
  std::atomic<bool> is_initialized_{false};

  // 读取图像设备的多线程，一个线程读取一个相机
  std::mutex cap_mutex_;
  std::vector<std::thread> cam_threads;
};
}  // namespace infinite_sense
