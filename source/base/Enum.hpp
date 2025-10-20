#pragma once
#include <string_view>

#define ENUM_NAMES(n, args...)                                                 \
  constexpr const std::string_view n##_names[] = {args};                       \
  template <> constexpr std::string_view to_string(n value) {                  \
    return n##_names[static_cast<int>(value)];                                 \
  }

namespace Sint {
template <typename ENUM> constexpr std::string_view to_string(ENUM value);
} // namespace Sint
