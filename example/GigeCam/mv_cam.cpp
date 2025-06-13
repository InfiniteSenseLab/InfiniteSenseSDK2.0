#include "mv_cam.h"
#include "infinite_sense.h"
#include "MvCameraControl.h"
namespace infinite_sense {
bool IsColor(const MvGvspPixelType type) {
  switch (type) {
    case PixelType_Gvsp_BGR8_Packed:
    case PixelType_Gvsp_YUV422_Packed:
    case PixelType_Gvsp_YUV422_YUYV_Packed:
    case PixelType_Gvsp_BayerGR8:
    case PixelType_Gvsp_BayerRG8:
    case PixelType_Gvsp_BayerGB8:
    case PixelType_Gvsp_BayerBG8:
    case PixelType_Gvsp_BayerGB10:
    case PixelType_Gvsp_BayerGB10_Packed:
    case PixelType_Gvsp_BayerBG10:
    case PixelType_Gvsp_BayerBG10_Packed:
    case PixelType_Gvsp_BayerRG10:
    case PixelType_Gvsp_BayerRG10_Packed:
    case PixelType_Gvsp_BayerGR10:
    case PixelType_Gvsp_BayerGR10_Packed:
    case PixelType_Gvsp_BayerGB12:
    case PixelType_Gvsp_BayerGB12_Packed:
    case PixelType_Gvsp_BayerBG12:
    case PixelType_Gvsp_BayerBG12_Packed:
    case PixelType_Gvsp_BayerRG12:
    case PixelType_Gvsp_BayerRG12_Packed:
    case PixelType_Gvsp_BayerGR12:
    case PixelType_Gvsp_BayerGR12_Packed:
      return true;
    default:
      return false;
  }
}
bool IsMono(const MvGvspPixelType type) {
  switch (type) {
    case PixelType_Gvsp_Mono8:
    case PixelType_Gvsp_Mono10:
    case PixelType_Gvsp_Mono10_Packed:
    case PixelType_Gvsp_Mono12:
    case PixelType_Gvsp_Mono12_Packed:
      return true;
    default:
      return false;
  }
}

bool PrintDeviceInfo(const MV_CC_DEVICE_INFO *info) {
  if (info == nullptr) {
    LOG(WARNING) << "[WARNING] Failed to get camera details. Skipping...";
    return false;
  }
  LOG(INFO) << "-------------------------------------------------------------";
  LOG(INFO) << "----------------------Camera Device Info---------------------";
  if (info->nTLayerType == MV_GIGE_DEVICE) {
    const unsigned int n_ip1 = ((info->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
    const unsigned int n_ip2 = ((info->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
    const unsigned int n_ip3 = ((info->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
    const unsigned int n_ip4 = (info->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);
    LOG(INFO) << "  Device Model Name    : " << info->SpecialInfo.stGigEInfo.chModelName;
    LOG(INFO) << "  Current IP Address   : " << n_ip1 << "." << n_ip2 << "." << n_ip3 << "." << n_ip4;
    LOG(INFO) << "  User Defined Name    : " << info->SpecialInfo.stGigEInfo.chUserDefinedName;
  } else if (info->nTLayerType == MV_USB_DEVICE) {
    LOG(INFO) << "  Device Model Name    : " << info->SpecialInfo.stUsb3VInfo.chModelName;
    LOG(INFO) << "  User Defined Name    : " << info->SpecialInfo.stUsb3VInfo.chUserDefinedName;
  } else {
    LOG(ERROR) << "[ERROR] Unsupported camera type!";
    return false;
  }
  LOG(INFO) << "-------------------------------------------------------------";
  return true;
}

MvCam::~MvCam() { Stop(); }

bool MvCam::Initialization() {
  int n_ret = MV_OK;
  MV_CC_DEVICE_INFO_LIST st_device_list{};
  memset(&st_device_list, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
  n_ret = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &st_device_list);
  if (MV_OK != n_ret) {
    LOG(ERROR) << "MV_CC_EnumDevices fail! n_ret [" << n_ret << "]";
  }
  if (st_device_list.nDeviceNum > 0) {
    for (size_t i = 0; i < st_device_list.nDeviceNum; i++) {
      MV_CC_DEVICE_INFO *p_device_info = st_device_list.pDeviceInfo[i];
      if (nullptr == p_device_info) {
        continue;
      }
      PrintDeviceInfo(p_device_info);
    }
  } else {
    LOG(ERROR) << "Not find GIGE or USB Cam Devices!";
    return false;
  }
  LOG(INFO) << "Number of cameras detected : " << st_device_list.nDeviceNum;
  for (size_t i = 0; i < st_device_list.nDeviceNum; i++) {
    handles_.emplace_back(nullptr);
    rets_.push_back(MV_OK);
  }
  // 一共找到多少个设备,分别对所有的设备进行初始化
  for (unsigned int i = 0; i < st_device_list.nDeviceNum; ++i) {
    // 检测到有多少个相机要全部进行初始化。
    // 选择设备并创建句柄
    rets_[i] = MV_CC_CreateHandleWithoutLog(&handles_[i], st_device_list.pDeviceInfo[i]);
    if (MV_OK != rets_[i]) {
      LOG(ERROR) << "MV_CC_CreateHandle fail! n_ret [" << rets_[i] << "]";
    }
    // open device
    rets_[i] = MV_CC_OpenDevice(handles_[i]);
    if (MV_OK != rets_[i]) {
      LOG(ERROR) << "MV_CC_OpenDevice fail! n_ret [" << rets_[i] << "]";
    }
    // ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal
    if (st_device_list.pDeviceInfo[i]->nTLayerType == MV_GIGE_DEVICE) {
      int n_packet_size = MV_CC_GetOptimalPacketSize(handles_[i]);
      if (n_packet_size > 0) {
        rets_[i] = MV_CC_SetIntValue(handles_[i], "GevSCPSPacketSize", n_packet_size);
        if (rets_[i] != MV_OK) {
          LOG(WARNING) << "Set Packet Size fail n_ret [0x" << std::hex << rets_[i] << "]";
        }
      } else {
        LOG(WARNING) << "Get Packet Size fail n_ret [0x" << std::hex << n_packet_size << "]";
      }
    }
    // 设置触发模式为off
    // rets_[i] = MV_CC_SetEnumValue(handles_[i], "TriggerMode", 1);
    // if (MV_OK != rets_[i]) {
    //   printf("MV_CC_SetTriggerMode fail! n_ret [%x]\n", rets_[i]);
    // }
    // 设置SDK内部图像缓存节点个数，大于等于1，在抓图前调用 1-30个缓存
    rets_[i] = MV_CC_SetImageNodeNum(handles_[i], 100);
    if (MV_OK != rets_[i]) {
      LOG(ERROR) << "MV_CC_SetImageNodeNum fail! n_ret [" << rets_[i] << "]";
    }
    // start grab image
    rets_[i] = MV_CC_StartGrabbing(handles_[i]);
    if (MV_OK != rets_[i]) {
      LOG(ERROR) << "MV_CC_StartGrabbing fail! n_ret [" << rets_[i] << "]";
    }
    LOG(INFO) << "Camera " << i << " opens to completion.";
  }
  if (0 == st_device_list.nDeviceNum) {
    return true;
  } else {
    return false;
  }
}

void MvCam::Stop() {
  Disable();
  std::this_thread::sleep_for(std::chrono::milliseconds{500});
  for (auto &cam_thread : cam_threads) {
    while (cam_thread.joinable()) {
      cam_thread.join();
    }
  }
  cam_threads.clear();
  cam_threads.shrink_to_fit();
  for (size_t i = 0; i < handles_.size(); ++i) {
    int n_ret = MV_OK;
    n_ret = MV_CC_StopGrabbing(handles_[i]);
    if (MV_OK != n_ret) {
      LOG(ERROR) << "MV_CC_StopGrabbing fail! n_ret [" << n_ret << "]";
    }
    n_ret = MV_CC_CloseDevice(handles_[i]);
    if (MV_OK != n_ret) {
      LOG(ERROR) << "MV_CC_CloseDevice fail! n_ret [" << n_ret << "]";
    }
    if (n_ret != MV_OK) {
      if (!handles_[i]) {
        MV_CC_DestroyHandle(handles_[i]);
        handles_[i] = nullptr;
      }
    }
    LOG(INFO) << "Exit  " << i << "  cam ";
  }
}
void MvCam::Receive(void *handle, const std::string &name) {
  unsigned int last_count = 0;
  MV_FRAME_OUT st_out_frame;
  CamData cam_data;
  Messenger &messenger = Messenger::GetInstance();
  while (is_running) {
    memset(&st_out_frame, 0, sizeof(MV_FRAME_OUT));
    int n_ret = MV_CC_GetImageBuffer(handle, &st_out_frame, 10);
    if (n_ret == MV_OK) {
      MVCC_FLOATVALUE expose_time;
      n_ret = MV_CC_GetExposureTime(handle, &expose_time);
      if (n_ret != MV_OK) {
        LOG(ERROR) << "Get ExposureTime fail! n_ret [0x" << std::hex << n_ret << "]";
      }
      // 这里的time_stamp_us是相机触发时间，需要加上曝光时间的一半，以获得相机拍摄的时间
      if (params.find(name) == params.end()) {
        LOG(ERROR) << "cam: " << name << " not found!";
      } else {
        if (uint64_t time; GET_LAST_TRIGGER_STATUS(params[name], time)) {
          cam_data.time_stamp_us = time + static_cast<uint64_t>(expose_time.fCurValue / 2.);
        } else {
          LOG(ERROR) << "Trigger cam: " << name << " not found!";
        }
      }
      MvGvspPixelType en_dst_pixel_type = PixelType_Gvsp_Undefined;
      unsigned int n_channel_num = 0;
      // 如果是彩色则转成RGB8
      if (IsColor(st_out_frame.stFrameInfo.enPixelType)) {
        n_channel_num = 3;
        en_dst_pixel_type = PixelType_Gvsp_RGB8_Packed;
      }
      // 如果是黑白则转换成Mono8
      else if (IsMono(st_out_frame.stFrameInfo.enPixelType)) {
        n_channel_num = 1;
        en_dst_pixel_type = PixelType_Gvsp_Mono8;
      }
      if (n_channel_num != 0) {
        cam_data.name = name;
        if (en_dst_pixel_type == PixelType_Gvsp_Mono8) {
          cam_data.image = GMat(st_out_frame.stFrameInfo.nHeight, st_out_frame.stFrameInfo.nWidth,
                                GMatType<uint8_t, 1>::Type, st_out_frame.pBufAddr);
        }
        if (en_dst_pixel_type == PixelType_Gvsp_RGB8_Packed) {
          cam_data.image = GMat(st_out_frame.stFrameInfo.nHeight, st_out_frame.stFrameInfo.nWidth,
                                GMatType<uint8_t, 3>::Type, st_out_frame.pBufAddr);
        }
        messenger.PubStruct(name, &cam_data, sizeof(cam_data));
        if (last_count == 0) {
          last_count = st_out_frame.stFrameInfo.nFrameNum;
        } else {
          last_count++;
          if (last_count != st_out_frame.stFrameInfo.nFrameNum) {
            LOG(WARNING) << "Loss of data from cam connection : " << last_count;
            last_count = 0;
          }
        }
      }
    }
    if (nullptr != st_out_frame.pBufAddr) {
      n_ret = MV_CC_FreeImageBuffer(handle, &st_out_frame);
      if (n_ret != MV_OK) {
        LOG(ERROR) << "Free Image Buffer fail! n_ret [0x" << std::hex << n_ret << "]";
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds{2});
  }
}
void MvCam::Start() {
  for (const auto &handle : handles_) {
    int n_ret = MV_OK;
    MVCC_STRINGVALUE pst_value;
    n_ret = MV_CC_GetDeviceUserID(handle, &pst_value);
    if (n_ret != MV_OK) {
      LOG(ERROR) << "Get DeviceUserID fail! n_ret [0x" << std::hex << n_ret << "]";
    }
    Enable();
    auto name = std::string(pst_value.chCurValue);
    if (name.empty()) {
      // 相机名称默认从1开始
      static int cam_index{1};
      name = "cam_" + std::to_string(cam_index++);
      LOG(WARNING) << "Camera name is empty,Create new name: " << name;
    }
    else {
      LOG(INFO) << "Camera name is " << name;
    }
    cam_threads.emplace_back(&MvCam::Receive, this, handle, name);
    LOG(INFO) << "Camera name is " << name << " start.";
  }
}
}  // namespace infinite_sense
