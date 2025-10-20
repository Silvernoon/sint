#include "String.hpp"
#include "Unicode.hpp"
#include <cstddef>

namespace Sint {

String::String(String const &s) : m_string(s.m_string) {}
String::String(String &&s) : m_string(std::move(s.m_string)) {}

String::String(char const *s) : m_string(s) {}
String::String(char const *s, size_t n) : m_string(s, n) {}
String::String(std::string const &s) : m_string(s) {}
String::String(std::string &&s) noexcept : m_string(std::move(s)) {}

String::String(std::wstring const &s) {
  reserve(s.length());
  for (char32_t c : s)
    append(c);
}

std::string const &String::utf8() const { return m_string; }

//__attribute__((__always_inline__)) size_t String::size() const { return 5; }

void String::clear() { m_string.clear(); }
void String::reserve(size_t n) { m_string.reserve(n); }

void String::append(String const &s) { m_string.append(s.m_string); }
void String::append(std::string const &s) { m_string.append(s); }
void String::append(char const *s) { m_string.append(s); };
void String::append(char const *s, size_t n) { m_string.append(s, n); };

void String::append(char32_t const *s) {
  while (*s)
    append(*s++);
}

void String::append(char32_t const *s, size_t n) {
  for (size_t i = 0; i < n; ++i)
    append(s[i]);
}

void String::append(char32_t c) {
  char utf32[4];
  size_t size = utf32ToUtf8(c, utf32);
  m_string.append(utf32, size);
}

void String::prepend(String const &s) {
  auto ns = s;
  ns.append(*this);
  *this = std::move(ns);
}

void String::prepend(std::string const &s) {
  auto ns = String(s);
  ns.append(*this);
  *this = std::move(ns);
}

void String::prepend(char const *s) {
  auto ns = String(s);
  ns.append(*this);
  *this = std::move(ns);
}

void String::prepend(char const *s, size_t n) {
  auto ns = String(s, n);
  ns.append(*this);
  *this = std::move(ns);
}

void String::prepend(char32_t const *s) {
  auto ns = String(s);
  ns.append(*this);
  *this = std::move(ns);
}

void String::prepend(char32_t const *s, size_t n) {
  auto ns = String(s, n);
  ns.append(*this);
  *this = std::move(ns);
}

void String::prepend(char32_t c) {
  auto ns = String(c, 1);
  ns.append(*this);
  *this = std::move(ns);
}

String &String::operator=(String const &s) {
  m_string = s.m_string;
  return *this;
}

String &String::operator=(String &&s) {
  m_string = std::move(s.m_string);
  return *this;
}

String &String::operator+=(String const &s) {
  append(s);
  return *this;
}

String &String::operator+=(std::string const &s) {
  append(s);
  return *this;
}

String &String::operator+=(char const *s) {
  append(s);
  return *this;
}

String &String::operator+=(char32_t const *s) {
  append(s);
  return *this;
}

String &String::operator+=(char32_t c) {
  append(c);
  return *this;
}

std::ostream &operator<<(std::ostream &os, String const &s) {
  os << s.utf8();
  return os;
}

std::istream &operator>>(std::istream &is, String &s) {
  std::string temp;
  is >> temp;
  s = String(std::move(temp));
  return is;
}

} // namespace Sint
