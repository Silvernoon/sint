#include "Logger.hpp"
#include "IO.hpp"
#include "Set.hpp"
#include "String.hpp"
#include "Thread.hpp"
#include "Time.hpp"

namespace Sint {

FileLogSink::FileLogSink(StringView name, bool trunc) {
  m_output = OutputFile(
      name.data(),
      std::ios::out |
          (trunc ? std::ios::trunc : static_cast<std::ios_base::openmode>(0)));
}

void FileLogSink::log(LogLevel level, StringView msg) {
  String line = strf("[{}] [{}] {}", Time::printCurrentTime(), 2, msg);
  m_output << line << std::endl;
}

void Logger::addSink(LogSink *sink) { s_sink.insert(sink); }

Mutex Logger::s_mutex;
HashSet<LogSink *> Logger::s_sink = {new FileLogSink("st.log")};

} // namespace Sint
