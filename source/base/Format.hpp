#pragma once
#include <format>
#include <string_view>

namespace Sint {

template <typename... T>
inline std::string strf(std::string_view str, T &&...args) {
  return std::vformat(str, std::forward<T>(args)...);
}
} // namespace Sint
