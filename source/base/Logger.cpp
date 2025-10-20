#include "Logger.hpp"
#include "Enum.hpp"
#include "Format.hpp"
#include "Set.hpp"
#include "Thread.hpp"
#include "Time.hpp"
#include <fstream>
#include <iostream>
#include <memory>

namespace Sint {

ENUM_NAMES(LogLevel, "Debug", "Info", "Warn", "Error");

LogSink::LogSink() : m_level(LogLevel::Info) {}

LogLevel LogSink::level() { return m_level; }

void LogSink::setLevel(LogLevel level) { m_level = level; }

void StdoutLogSink::log(LogLevel level, std::string_view msg) {
  MutexLocker lock(m_mutex);
  std::cout << strf("[{}] {}", to_string(level), msg) << std::endl;
  std::cout.flush();
}

FileLogSink::FileLogSink(std::string_view name, LogLevel level, bool trunc) {
  m_output = std::ofstream(
      name.data(),
      std::ios::app |
          (trunc ? std::ios::trunc : static_cast<std::ios_base::openmode>(0)));
}

void FileLogSink::log(LogLevel level, std::string_view msg) {
  MutexLocker lock(m_mutex);
  m_output << strf("[{}] [{}] {}", Time::printCurrentTime(), to_string(level),
                   msg)
           << std::endl;
}

void Logger::addSink(LogSinkPtr s) {
  MutexLocker locker(s_mutex);
  s_sinks.insert(s);
}

void Logger::removeSink(LogSinkPtr s) {
  MutexLocker locker(s_mutex);
  s_sinks.erase(s);
}

LogSinkPtr Logger::stdoutSink() { return s_stdoutSink; }

std::shared_ptr<StdoutLogSink> Logger::s_stdoutSink =
    std::make_shared<StdoutLogSink>();
HashSet<LogSinkPtr> Logger::s_sinks = {
    std::make_shared<StdoutLogSink>(),
    std::make_shared<FileLogSink>("sint.log", LogLevel::Info)};
Mutex Logger::s_mutex;

} // namespace Sint
