#include "IO.hpp"
#include <fstream>
#include <iostream>
#include <string>
namespace Utils {

/**
 */
std::string LoadFile(const char *path) {
  std::ifstream file(path, std::ios::binary); // 以二进制模式打开文件
  if (!file) {                                // 检查文件是否成功打开
    throw std::runtime_error("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
  }
  return std::string((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
}
} // namespace Utils
