#pragma once
#include "Set.hpp"
#include "String.hpp"
#include "Thread.hpp"
#include <fstream>
#include <memory>
#include <string>
#include <string_view>

namespace Sint {

enum class LogLevel { Debug, Info, Warn, Error };

CLASS_Ptr(LogSink);

/**
 * A sink for Logger messages.
 */
class LogSink {
public:
  LogSink();
  virtual ~LogSink() = default;

  virtual void log(LogLevel level, std::string_view msg) = 0;

  LogLevel level();
  void setLevel(LogLevel);

private:
  Atomic<LogLevel> m_level;
};

class StdoutLogSink : public LogSink {
public:
  virtual void log(LogLevel level, std::string_view msg) override;

private:
  Mutex m_mutex;
};

class FileLogSink : public LogSink {
public:
  FileLogSink(std::string_view name, LogLevel level, bool trunc = false);

  virtual void log(LogLevel level, std::string_view msg) override;

private:
  std::ofstream m_output;
  Mutex m_mutex;
};

class Logger {
public:
  static void addSink(LogSinkPtr);
  static void removeSink(LogSinkPtr);

  // Default LogSink that outputs to stdout.
  static LogSinkPtr stdoutSink();

  template <typename... Args>
  static void debug(std::string_view msg, Args const &...args);
  template <typename... Args>
  static void info(std::string_view msg, Args const &...args);
  template <typename... Args>
  static void warn(std::string_view msg, Args const &...args);
  template <typename... Args>
  static void error(std::string_view msg, Args const &...args);

private:
  template <typename... Args>
  static void logf(LogLevel level, std::string_view msg, Args const &...args);

  static std::shared_ptr<StdoutLogSink> s_stdoutSink;
  static HashSet<LogSinkPtr> s_sinks;
  static Mutex s_mutex;
};

template <typename... Args>
void Logger::logf(LogLevel level, std::string_view msg, Args const &...args) {
  std::string out = strf(msg, args...);
  MutexLocker locker(s_mutex);
  for (auto const &v : s_sinks)
    if (v->level() <= level)
      v->log(level, out);
}

template <typename... Args>
void Logger::info(std::string_view msg, Args const &...args) {
  logf(LogLevel::Info, msg, args...);
}

template <typename... Args>
void Logger::debug(std::string_view msg, Args const &...args) {
  logf(LogLevel::Debug, msg, args...);
}

template <typename... Args>
void Logger::warn(std::string_view msg, Args const &...args) {
  logf(LogLevel::Warn, msg, args...);
}

template <typename... Args>
void Logger::error(std::string_view msg, Args const &...args) {
  logf(LogLevel::Error, msg, args...);
}

} // namespace Sint
