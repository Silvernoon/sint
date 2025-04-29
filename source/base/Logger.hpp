#pragma once
#include "IO.hpp"
#include "Set.hpp"
#include "String.hpp"
#include "Thread.hpp"

namespace Sint {

enum class LogLevel { Debug, Info, Warn, Error, Fatal };

/**
 * A sink for Logger messages.
 */
class LogSink {
public:
  virtual void log(LogLevel level, StringView msg) = 0;
};

class FileLogSink : public LogSink {
  OutputFile m_output;

public:
  FileLogSink(StringView name, bool trunc = false);

  virtual void log(LogLevel level, StringView msg) override;
};

class Logger {
  static Mutex s_mutex;
  static HashSet<LogSink *> s_sink;

  template <typename... Args>
  static void logf(LogLevel level, StringView msg, Args const &...args);

public:
  template <typename... Args>
  static void info(StringView msg, Args const &...args);

  template <typename... Args>
  static void debug(StringView msg, Args const &...args);

  template <typename... Args>
  static void warn(StringView msg, Args const &...args);

  template <typename... Args>
  static void error(StringView msg, Args const &...args);

  static void addSink(LogSink *sink);
};

template <typename... Args>
void Logger::logf(LogLevel level, StringView msg, Args const &...args) {
  MutexLocker locker(s_mutex);
  String out = strf(msg, args...);

  for (LogSink *v : s_sink) {
    v->log(level, out);
  }
}

template <typename... Args>
void Logger::info(StringView msg, Args const &...args) {
  logf(LogLevel::Info, msg, args...);
}

template <typename... Args>
void Logger::debug(StringView msg, Args const &...args) {
  logf(LogLevel::Debug, msg, args...);
}

template <typename... Args>
void Logger::warn(StringView msg, Args const &...args) {
  logf(LogLevel::Warn, msg, args...);
}

template <typename... Args>
void Logger::error(StringView msg, Args const &...args) {
  logf(LogLevel::Error, msg, args...);
}

} // namespace Sint
