#pragma once
#include <log.h>
#include <thread>
#include <zmq.hpp>
#include <functional>
#include <mutex>

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
  void Pub(const std::string& topic, const std::string& metadata);
  void PubStruct(const std::string& topic, const void* data, size_t size);
  void Sub(const std::string& topic, const std::function<void(const std::string&)>& callback);
  void SubStruct(const std::string& topic, const std::function<void(const void*, size_t)>& callback);

 private:
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
