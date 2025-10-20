#pragma once
#include "Exception.hpp"
#include "List.hpp"
#include "Ptr.hpp"
#include <string>

namespace Sint {

DEF_EXCEPTION(StringException, Exception);

/**
 * Unicode String class, which is a basic UTF-8 aware
 * wrapper around std::string.  Provides methods for UTF-32 type.
 */
class String {
public:
  typedef std::basic_string<char32_t> WideString;

  String() = default;
  String(String const &);
  String(String &&);

  String(char const *);
  String(char const *, size_t);
  String(std::string const &);
  String(std::string &&) noexcept;

  String(std::wstring const &);
  String(char32_t const *);
  String(char32_t const *, size_t);
  String(char32_t, size_t);
  String(char32_t &&, size_t);

  explicit String(char32_t);

  // const& to internal utf8 data
  std::string const &utf8() const;

  size_t size() const;

  void clear();
  void reserve(size_t n);

  void append(String const &);
  void append(std::string const &);
  void append(char const *);
  void append(char const *, size_t);
  void append(char32_t const *);
  void append(char32_t const *, size_t);
  void append(char32_t);

  void prepend(String const &);
  void prepend(std::string const &);
  void prepend(char const *);
  void prepend(char const *, size_t);
  void prepend(char32_t const *);
  void prepend(char32_t const *, size_t);
  void prepend(char32_t);

  String &operator=(String const &);
  String &operator=(String &&);

  String &operator+=(String const &s);
  String &operator+=(std::string const &s);
  String &operator+=(char const *s);
  String &operator+=(char32_t const *s);
  String &operator+=(char32_t c);

  friend std::ostream &operator<<(std::ostream &os, String const &s);
  friend std::istream &operator>>(std::istream &is, String &s);

private:
  std::string m_string;
};

} // namespace Sint
