#include "Logger.hpp"
#include "Enum.hpp"
#include "IO.hpp"
#include "Set.hpp"
#include "String.hpp"
#include "Thread.hpp"
#include "Time.hpp"
#include <iostream>

namespace Sint {

ENUM_NAMES(LogLevel, "Info", "Debug", "Warn", "Error");

inline String logf(LogLevel level, StringView msg) {
  return strf("[{}] [{}] {}", Time::printCurrentTime(), to_string(level), msg);
}

void StdLogSink::log(LogLevel level, StringView msg) {
  std::cout << logf(level, msg) << std::endl;
  std::cout.flush();
}

FileLogSink::FileLogSink(StringView name, bool trunc) {
  m_output = OutputFile(
      name.data(),
      std::ios::out |
          (trunc ? std::ios::trunc : static_cast<std::ios_base::openmode>(0)));
}

void FileLogSink::log(LogLevel level, StringView msg) {
  m_output << logf(level, msg) << std::endl;
}

void Logger::addSink(LogSink *sink) { s_sink.insert(sink); }

Mutex Logger::s_mutex;
HashSet<LogSink *> Logger::s_sink = {new FileLogSink("sint.log"),
                                     new StdLogSink};

} // namespace Sint
