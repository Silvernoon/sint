#pragma once

#include "Array.hpp"
#include <cstdint>

namespace Sint {

template <typename T, size_t N> class Vector : public Array<T, N> {
public:
  typedef Array<T, N> Base;

  template <size_t P, typename T2 = void>
  using Enable2D = typename std::enable_if<P == 2 && N == P, T2>::type;
};

typedef Vector<int, 2> Vec2I;
typedef Vector<unsigned, 2> Vec2U;
typedef Vector<float, 2> Vec2F;
typedef Vector<double, 2> Vec2D;
typedef Vector<uint8_t, 2> Vec2B;
typedef Vector<size_t, 2> Vec2S;
} // namespace Sint
