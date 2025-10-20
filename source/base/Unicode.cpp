#include "Unicode.hpp"

namespace Sint {

inline void throwInvalidUtf32CodePoint(char32_t val) {
  throw UnicodeException::format(
      "Invalid UTF-32 code point {} encountered while trying to encode UTF-8",
      (int32_t)val);
}

size_t utf32ToUtf8(char32_t utf32, char *utf8) {
  if (utf32 > 0x10FFFFu)
    throwInvalidUtf32CodePoint(utf32);

  if (utf32 <= 0x7Fl) { // 127
    utf8[0] = utf32;
    return 1;
  } else if (utf32 <= 0x7FFl) {
    utf8[0] = 0xc0 | ((utf32 >> 6) & 0x1f);
    utf8[1] = 0x80 | ((utf32 >> 0) & 0x3f);
    return 2;
  } else if (utf32 <= 0x00FFFFl) {
    utf8[0] = 0xe0 | ((utf32 >> 12) & 0x0f);
    utf8[1] = 0x80 | ((utf32 >> 6) & 0x3f);
    utf8[2] = 0x80 | ((utf32 >> 0) & 0x3f);
    return 3;
  } else {
    utf8[0] = 0xf0 | ((utf32 >> 18) & 0x07);
    utf8[1] = 0x80 | ((utf32 >> 12) & 0x3f);
    utf8[2] = 0x80 | ((utf32 >> 6) & 0x3f);
    utf8[3] = 0x80 | ((utf32 >> 0) & 0x3f);
    return 4;
  }
}
} // namespace Sint
