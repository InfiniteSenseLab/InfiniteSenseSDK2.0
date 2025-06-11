#include "usb.h"
#include "infinite_sense.h"
#include "ptp.h"
#include "data.h"

namespace infinite_sense {

UsbManager::UsbManager(std::string port, const int baud_rate) : port_(std::move(port)), started_(false) {
  serial_ptr_ = std::make_unique<serial::Serial>();
  try {
    serial_ptr_->setPort(port_);
    serial_ptr_->setBaudrate(baud_rate);
    serial::Timeout to = serial::Timeout::simpleTimeout(1000);
    serial_ptr_->setTimeout(to);
    serial_ptr_->open();
    if (serial_ptr_->isOpen()) {
      serial_ptr_->flush();
      LOG(INFO) << "Serial port " << port_ << " opened successfully.";
    } else {
      LOG(ERROR) << "Failed to open serial port: " << port_;
      return;
    }
    ptp_ = std::make_unique<Ptp>();
    ptp_->SetUsbPtr(serial_ptr_);
  } catch (const serial::IOException& e) {
    LOG(ERROR) << "Serial IO exception on port " << port_ << ": " << e.what();
    if (serial_ptr_->isOpen()) {
      serial_ptr_->close();
    }
  }
}

UsbManager::~UsbManager() {
  Stop();  // 确保资源优雅释放
}

void UsbManager::Start() {
  if (!serial_ptr_ || !serial_ptr_->isOpen()) {
    LOG(ERROR) << "Cannot start USB manager: Serial port not open.";
    return;
  }
  started_ = true;
  rx_thread_ = std::thread(&UsbManager::Receive, this);
  tx_thread_ = std::thread(&UsbManager::TimeStampSynchronization, this);
  LOG(INFO) << "USB manager started.";
}

void UsbManager::Stop() {
  if (!started_) {
    return;
  }
  started_ = false;
  if (rx_thread_.joinable()) {
    rx_thread_.join();
  }
  if (tx_thread_.joinable()) {
    tx_thread_.join();
  }
  if (serial_ptr_ && serial_ptr_->isOpen()) {
    serial_ptr_->close();
    LOG(INFO) << "Serial port " << port_ << " closed.";
  }
  LOG(INFO) << "USB manager stopped";
}

void UsbManager::Receive() const {
  while (started_) {
    try {
      if (!serial_ptr_ || !serial_ptr_->isOpen()) {
        break;
      }
      if (serial_ptr_->available()) {
        const std::string serial_recv = serial_ptr_->readline();
        if (serial_recv.empty()) {
          LOG(WARNING) << "Received empty string.";
          continue;
        }
        auto json_data = nlohmann::json::parse(serial_recv, nullptr, false);
        if (json_data.is_discarded()) {
          LOG(WARNING) << "Received malformed JSON: " << serial_recv;
          continue;
        }
        ptp_->ReceivePtpData(json_data);
        ProcessTriggerData(json_data);
        ProcessIMUData(json_data);
        ProcessGPSData(json_data);
        ProcessLOGData(json_data);
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    } catch (const std::exception& e) {
      LOG(ERROR) << "Receive thread exception: " << e.what();
    }
  }
}

void UsbManager::TimeStampSynchronization() const {
  while (started_) {
    try {
      ptp_->SendPtpData();
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    } catch (const std::exception& e) {
      LOG(ERROR) << "Timestamp sync exception: " << e.what();
    }
  }
}

}  // namespace infinite_sense
