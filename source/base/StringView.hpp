#pragma once
#include "String.hpp"
#include <string_view>

namespace Sint {

/**
 * A StringViewView version of Sint::String
 */
class StringView {
public:
  StringView() = default;
  StringView(StringView const &);
  StringView(StringView &&) noexcept;
  StringView(String const &);

  StringView(char const *);
  StringView(char const *, size_t);
  StringView(std::string_view const &);
  StringView(std::string_view &&) noexcept;
  StringView(std::string const &);

  StringView(char32_t const *s);
  StringView(char32_t const *s, size_t n);

  std::string_view const &utf8() const;

  char const *utf8Ptr() const;

  size_t size() const;

private:
  std::string_view m_view;
};

} // namespace Sint
