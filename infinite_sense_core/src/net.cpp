#include "infinite_sense.h"
#include "ptp.h"
#include "data.h"
#include "net.h"

namespace infinite_sense {

NetManager::NetManager(std::string target_ip, unsigned short port) : port_(port), target_ip_(std::move(target_ip)) {
  net_ptr_ = std::make_shared<UDPSocket>();
  const uint64_t curr_time = static_cast<uint64_t>(
      std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch())
          .count());
  net_ptr_->sendTo(reinterpret_cast<const uint8_t*>(&curr_time), sizeof(curr_time), target_ip_, port_);
  ptp_ = std::make_unique<Ptp>();
  ptp_->SetNetPtr(net_ptr_, target_ip_, port_);
}

NetManager::~NetManager() {
  Stop();
  if (net_ptr_) {
    net_ptr_->disconnect();
    net_ptr_.reset();
  }
}

void NetManager::Start() {
  if (started_) {
    return;
  }
  started_ = true;
  rx_thread_ = std::thread(&NetManager::Receive, this);
  tx_thread_ = std::thread(&NetManager::TimeStampSynchronization, this);
  LOG(INFO) << "Net manager started";
}

void NetManager::Stop() {
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
  LOG(INFO) << "Net manager stopped";
}

void NetManager::Receive() const {
  constexpr size_t k_buffer_size = 65536;
  std::array<uint8_t, k_buffer_size> buffer{};
  std::string source_address;
  unsigned short source_port = 0;

  while (started_) {
    const int size = net_ptr_->recvFrom(buffer.data(), k_buffer_size, source_address, source_port);
    if (size <= 0) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      continue;
    }

    try {
      std::string recv_data(reinterpret_cast<char*>(buffer.data()), size);
      if (recv_data.empty()) {
        continue;
      }
      auto json_data = nlohmann::json::parse(recv_data, nullptr, false);
      if (json_data.is_discarded()) {
        LOG(WARNING) << "Received malformed JSON";
        continue;
      }
      ptp_->ReceivePtpData(json_data);
      ProcessTriggerData(json_data);
      ProcessIMUData(json_data);
      ProcessGPSData(json_data);
      ProcessLOGData(json_data);

    } catch (const std::exception& e) {
      LOG(ERROR) << "Exception during JSON handling: " << e.what();
    }
  }
}

void NetManager::TimeStampSynchronization() const {
  while (started_) {
    try {
      ptp_->SendPtpData();
      std::this_thread::sleep_for(std::chrono::milliseconds(10));  // 限制频率，防止死循环占满 CPU
    } catch (const std::exception& e) {
      LOG(ERROR) << "Timestamp sync error: " << e.what();
    }
  }
}

}  // namespace infinite_sense
