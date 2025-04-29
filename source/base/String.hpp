#pragma once

#include <format>
#include <string>
#include <string_view>

namespace Sint {
using StringView = std::string_view;
using String = std::string;

template <typename... Args> String strf(StringView str, Args &&...args) {
  return std::vformat(str, std::make_format_args(args...));
}

} // namespace Sint
