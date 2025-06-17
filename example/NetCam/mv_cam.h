#pragma once
#include "infinite_sense.h"
namespace infinite_sense {
class MvCam final : public Sensor {
 public:
  ~MvCam() override;

  bool Initialization() override;
  void Stop() override;
  void Start() override;

 private:
  void Receive(void* handle, const std::string&) override;
  std::vector<int> rets_;
  std::vector<void*> handles_;
};
}  // namespace infinite_sense
