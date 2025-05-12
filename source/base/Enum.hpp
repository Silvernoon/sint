#include "String.hpp"
#include <string>

#define ENUM_NAMES(n, args...)                                                 \
  constexpr const Sint::StringView n##_names[] = {args};                       \
  template <> constexpr Sint::String to_string(n value) {                      \
    return Sint::String(n##_names[static_cast<int>(value)]);                   \
  }

namespace Sint {
template <typename ENUM> constexpr String to_string(ENUM value);
} // namespace Sint
