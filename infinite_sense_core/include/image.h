#pragma once
#include <cstddef>
#include <cstdint>
namespace infinite_sense {
#if defined(HAS_OPENCV) || defined(HAS_OPENCV3)
#include <opencv2/core/core.hpp>
#else
typedef unsigned char uchar;
#endif

enum GElementType {
  GElementType_8U = 0,
  GElementType_8S = 1,
  GElementType_16U = 2,
  GElementType_16S = 3,
  GElementType_32S = 4,
  GElementType_32F = 5,
  GElementType_64F = 6,
  GElementType_UserType = 7
};

template <typename>
class GElement {
 public:
  enum { Type = GElementType_UserType };
};

template <>
class GElement<uint8_t> {
 public:
  enum { Type = GElementType_8U };
};

template <>
class GElement<char> {
 public:
  enum { Type = GElementType_8S };
};

template <>
class GElement<int16_t> {
 public:
  enum { Type = GElementType_16S };
};

template <>
class GElement<uint16_t> {
 public:
  enum { Type = GElementType_16U };
};

template <>
class GElement<int32_t> {
 public:
  enum { Type = GElementType_32S };
};

template <>
class GElement<float> {
 public:
  enum { Type = GElementType_32F };
};

template <>
class GElement<double> {
 public:
  enum { Type = GElementType_64F };
};

template <typename EleType = uint8_t, int channelSize = 1>
struct GMatType {
  enum { Type = ((GElement<EleType>::Type & 0x7) + ((channelSize - 1) << 3)) };
};

class GMat {
 public:
  GMat();

  GMat(int rows_, int cols_, int type = GMatType<>::Type, uchar* src = nullptr, bool copy = false,
       int image_align = 16);

  GMat(const GMat& ref);

  ~GMat();

  GMat& operator=(const GMat& rhs);

  static GMat Create(int rows, int cols, int type = GMatType<>::Type, uchar* src = nullptr, bool copy = false);

  static GMat Zeros(int rows, int cols, int type = GMatType<>::Type, uchar* src = nullptr, bool copy = false,
                    int image_align = 16);
  void Release();
  bool Empty() const { return !data; }
  int ElemSize() const { return Channels() * ElemSize1(); }
  int ElemSize1() const { return (1 << ((Type() & 0x7) >> 1)); }
  int Channels() const { return (Type() >> 3) + 1; }
  int Type() const { return flags; }
  int Total() const { return cols * rows; }
  GMat Clone() const { return {rows, cols, flags, data, true}; }
  template <typename C>
  C& At(int idx) {
    return static_cast<C*>(data)[idx];
  }
  template <typename C>
  C& At(const int ix, const int iy) {
    return static_cast<C*>(data)[iy * cols + ix];
  }
  template <typename Tp>
  Tp* Ptr(const int i0 = 0) {
    return static_cast<Tp*>(data + i0 * cols * ElemSize());
  }
  template <typename Tp>
  const Tp* Ptr(const int i0 = 0) const {
    return static_cast<Tp*>(data + i0 * cols * ElemSize());
  }
  GMat Row(const int idx = 0) const { return {1, cols, Type(), data + ElemSize() * cols * idx}; }
  int GetWidth() const { return cols; }
  int GetHeight() const { return rows; }

 private:
  template <typename Tp>
  static Tp* AlignPtr(Tp* ptr, int n = static_cast<int>(sizeof(Tp)));
  static void* FastMalloc(size_t size, int image_align = 16);
  static void FastFree(void* ptr);
  static size_t AlignSize(size_t sz, int n);

 public:
  int cols, rows, flags;
  uchar* data;
  mutable int* ref_count;
};
}  // namespace infinite_sense
