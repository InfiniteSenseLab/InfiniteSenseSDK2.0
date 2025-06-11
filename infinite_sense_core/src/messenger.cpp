#include "messenger.h"
#include "log.h"

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

void Messenger::Pub(const std::string& topic, const std::string& metadata) {
  try {
    publisher_.send(zmq::buffer(topic), zmq::send_flags::sndmore);
    publisher_.send(zmq::buffer(metadata), zmq::send_flags::dontwait);
  } catch (const zmq::error_t& e) {
    LOG(ERROR) << "Publish error: " << e.what();
  }
}

void Messenger::PubStruct(const std::string& topic, const void* data, const size_t size) {
  try {
    publisher_.send(zmq::buffer(topic), zmq::send_flags::sndmore);
    publisher_.send(zmq::buffer(data, size), zmq::send_flags::dontwait);
  } catch (const zmq::error_t& e) {
    LOG(ERROR) << "Publish struct error: " << e.what();
  }
}

void Messenger::Sub(const std::string& topic, const std::function<void(const std::string&)>& callback) {
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

void Messenger::SubStruct(const std::string& topic, const std::function<void(const void*, size_t)>& callback) {
  sub_threads_.emplace_back([this, topic, callback]() {
    try {
      auto context = zmq::context_t(1);
      zmq::socket_t subscriber(context, zmq::socket_type::sub);
      subscriber.connect(endpoint_);
      subscriber.set(zmq::sockopt::subscribe, topic);
      while (true) {
        zmq::message_t topic_msg, data_msg;
        if (!subscriber.recv(topic_msg) || !subscriber.recv(data_msg)) {
          LOG(WARNING) << "Subscription to topic [" << topic << "] failed.";
          continue;
        }
        if (std::string received_topic(static_cast<char*>(topic_msg.data()), topic_msg.size());
            received_topic != topic) {
          continue;
        }
        callback(data_msg.data(), data_msg.size());
      }
    } catch (const zmq::error_t& e) {
      LOG(ERROR) << "Exception in SubStruct for topic [" << topic << "]: " << e.what();
    }
  });
}

}  // namespace infinite_sense
