#include "Time.hpp"
#include "String.hpp"
#include <chrono>
#include <ctime>

using namespace std::chrono;

namespace Sint {
String Time::printCurrentTime() {
  time_point now = system_clock::now();
  std::ostringstream oss;
  oss << now;
  return oss.str();
}

} // namespace Sint
