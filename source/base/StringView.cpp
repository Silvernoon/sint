#include "StringView.hpp"

namespace Sint {

StringView::StringView(StringView const &s) : m_view(s.m_view) {}
StringView::StringView(StringView &&s) noexcept : m_view(s.m_view) {}
StringView::StringView(String const &s) : m_view(s.utf8()) {}

StringView::StringView(char const *s) : m_view(s) {}
StringView::StringView(char const *s, size_t n) : m_view(s, n) {}

StringView::StringView(std::string_view const &s) : m_view(s) {}
StringView::StringView(std::string_view &&s) noexcept : m_view(s) {}
StringView::StringView(std::string const &s) : m_view(s) {}

StringView::StringView(char32_t const *s)
    : m_view((char const *)s, sizeof(*s)) {}
StringView::StringView(char32_t const *s, size_t n)
    : m_view((char const *)s, n * sizeof(*s)) {}

std::string_view const &StringView::utf8() const { return m_view; }

char const *StringView::utf8Ptr() const { return m_view.data(); }

size_t StringView::size() const { return; }

} // namespace Sint
