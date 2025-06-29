#include "video_cam.h"
#include "infinite_sense.h"
namespace infinite_sense {

// 调用停止读取函数
VideoCam::~VideoCam() { Stop(); }

// 初始化摄像头
bool VideoCam::Initialization() {
  std::lock_guard<std::mutex> lock(cap_mutex_);
  if (!cap_.open(0)) {  // 打开默认摄像头
    // 打开失败报错
    std::cerr << "[OpenCVCam] Failed to open camera!" << std::endl;
    return false;
  }
  // 设置相机帧率，注意这里的帧率需要是 1. 摄像头支持的帧率 2. 尽量大于触发帧率，这样才能保证时间戳对上
  cap_.set(cv::CAP_PROP_FPS, 30);
  is_initialized_ = true;// 初始化标识
  std::cout << "[OpenCVCam] Camera initialized." << std::endl;
  return true;
}

// 停止读取函数 
void VideoCam::Stop() {
  is_running = false;// 初始化标识
  {
    std::lock_guard<std::mutex> lock(cap_mutex_);
    if (cap_.isOpened()) {
      cap_.release();// 释放摄像头设备
      std::cout << "[OpenCVCam] Camera released." << std::endl;
    }
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  for (auto& t : cam_threads) {
    if (t.joinable()) {
      t.join();
    }
  }
  // 关闭线程
  cam_threads.clear();
  cam_threads.shrink_to_fit();
}

// 相机读取函数 
void VideoCam::Receive(void *handle, const std::string &name) {
  // 自定义的相机类，包含1. 图像数据 2. 时间戳 3. 相机名称 
  CamData cam_data;
  // 统一的消息管理类
  Messenger &messenger = Messenger::GetInstance();

  // 初始化完成，运行的状态中
  while (is_running) {
    // 1. 读取相机中的一帧图像
    cv::Mat frame_bgr;
    {
      std::lock_guard<std::mutex> lock(cap_mutex_);
      if (!cap_.isOpened() || !cap_.read(frame_bgr)) {
        std::cerr << "[OpenCVCam] Failed to read frame!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        continue;
      }
    }

 
    // 这里的time_stamp_us是相机触发时间，调用 GET_LAST_TRIGGER_STATUS(params[name], time)) 获取name 对应设备最新触发时间
    if (params.find(name) == params.end()) {
      LOG(ERROR) << "cam: " << name << " not found!";
    } else {
      if (uint64_t time; GET_LAST_TRIGGER_STATUS(params[name], time)) {
        cam_data.time_stamp_us = time;
      } else {
        LOG(ERROR) << "Trigger cam: " << name << " not found!";
      }
    }

    // 相机的名称
    cam_data.name = name;
    // 相机的数据，直接把原始数据发送
    cam_data.image = GMat(frame_bgr.rows, frame_bgr.cols,
                          GMatType<uint8_t, 3>::Type, frame_bgr.data).Clone();
    messenger.PubStruct(name, &cam_data, sizeof(cam_data));
    std::this_thread::sleep_for(std::chrono::milliseconds{2});
  }
}

// 开始读取函数
void VideoCam::Start() {
  if (!is_initialized_) {
    std::cerr << "[OpenCVCam] Start failed: not initialized." << std::endl;
    return;
  }
  // 运行标识位
  is_running = true;
  // 开启一个线程并告诉其相机名称
  std::string name = "video_cam";
  cam_threads.emplace_back(&VideoCam::Receive, this, nullptr, name);
  std::cout << "[OpenCVCam] Camera capture started." << std::endl;
}
}  // namespace infinite_sense
