#pragma once
#include <log.h>
#include <thread>
#include <zmq.hpp>
#include <functional>
#include <mutex>
#include <google/protobuf/message.h>

namespace infinite_sense {
class Messenger {
 public:
  static Messenger& GetInstance() {
    static Messenger instance;
    return instance;
  }
  Messenger(const Messenger&) = delete;
  Messenger(const Messenger&&) = delete;
  Messenger& operator=(const Messenger&) = delete;
  bool PubProto(const std::string&,const std::shared_ptr<google::protobuf::Message>&);
 private:
  void PubStr(const std::string& topic, const std::string& metadata);
  void SubStr(const std::string& topic, const std::function<void(const std::string&)>& callback);
  Messenger();
  ~Messenger();
  void CleanUp();
  std::mutex mutex_;
  zmq::context_t context_{};
  zmq::socket_t publisher_{}, subscriber_{};
  std::string endpoint_{};
  std::vector<std::thread> sub_threads_;
};
}  // namespace infinite_sense
