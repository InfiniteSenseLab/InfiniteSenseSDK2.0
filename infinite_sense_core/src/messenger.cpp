#include "messenger.h"
#include "log.h"
#include <google/protobuf/any.pb.h>
namespace infinite_sense {

Messenger::Messenger() {
  try {
    endpoint_ = "tcp://127.0.0.1:4565";
    context_ = zmq::context_t(10);
    publisher_ = zmq::socket_t(context_, zmq::socket_type::pub);
    subscriber_ = zmq::socket_t(context_, zmq::socket_type::sub);
    publisher_.bind(endpoint_);
    subscriber_.connect(endpoint_);
    LOG(INFO) << "Link Net: " << endpoint_;
  } catch (const zmq::error_t& e) {
    LOG(ERROR) << "Net initialization error: " << e.what();
    CleanUp();
  }
}

Messenger::~Messenger() { CleanUp(); }

void Messenger::CleanUp() {
  try {
    publisher_.close();
    subscriber_.close();
    context_.close();
    for (auto& thread : sub_threads_) {
      if (thread.joinable()) {
        thread.join();
      }
    }
    LOG(INFO) << "Messenger clean up successful";
  } catch (...) {
    LOG(ERROR) << "Messenger clean up error";
  }
}

void Messenger::PubStr(const std::string& topic, const std::string& metadata) {
  try {
    std::lock_guard lock(mutex_);
    publisher_.send(zmq::buffer(topic), zmq::send_flags::sndmore);
    publisher_.send(zmq::buffer(metadata), zmq::send_flags::dontwait);
  } catch (const zmq::error_t& e) {
    LOG(ERROR) << "Publish error: " << e.what();
  }
}
bool Messenger::PubProto(const std::string& topic,
                              const std::shared_ptr<google::protobuf::Message>& message) {
  google::protobuf::Any any_msg;
  any_msg.PackFrom(message);
  const std::string serialized = any_msg.SerializeAsString();
  if (serialized.empty()) {
    return false;
  }
  PubStr(topic, serialized);
  return true;
}

void Messenger::SubStr(const std::string& topic, const std::function<void(const std::string&)>& callback) {
  sub_threads_.emplace_back([this, topic, callback]() {
    try {
      zmq::socket_t subscriber(context_, zmq::socket_type::sub);
      subscriber.connect(endpoint_);
      subscriber.set(zmq::sockopt::subscribe, topic);
      while (true) {
        zmq::message_t topic_msg, data_msg;
        if (!subscriber.recv(topic_msg) || !subscriber.recv(data_msg)) {
          LOG(WARNING) << "Subscription receive failed for topic: " << topic;
          continue;
        }
        if (std::string received_topic(static_cast<char*>(topic_msg.data()), topic_msg.size());
            received_topic != topic) {
          continue;
        }
        std::string data(static_cast<char*>(data_msg.data()), data_msg.size());
        callback(data);
      }
    } catch (const zmq::error_t& e) {
      LOG(ERROR) << "Exception in Sub thread for topic [" << topic << "]: " << e.what();
    }
  });
}
}  // namespace infinite_sense
