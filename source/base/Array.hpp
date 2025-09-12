#pragma once

#include <array>
#include <cstddef>

namespace Sint {

template <typename T, size_t N> class Array : public std::array<T, N> {
public:
  typedef std::array<T, N> Base;

  typedef T Element;
  const size_t Size = N;
};
} // namespace Sint
