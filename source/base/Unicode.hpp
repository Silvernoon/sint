#pragma once
#include "Exception.hpp"
#include <cstddef>

namespace Sint {
DEF_EXCEPTION(UnicodeException, Exception);

// Encode single utf32 char into up to 4 utf8 characters.
size_t utf32ToUtf8(char32_t utf32, char *utf8);
} // namespace Sint
