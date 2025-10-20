#include "Exception.hpp"
#include "Logger.hpp"

void fatalError(char const *message, bool showStackTrace) {
  if (showStackTrace)
#ifdef STAR_USE_CPPTRACE
    Logger::error("Fatal Error: {}\n{}", message, captureBacktrace());
#else
    Logger::error("Fatal Error: {}\n{}", message, outputStack(captureStack()));
#endif
  else
    Logger::error("Fatal Error: {}", message);

  std::abort();
}

void fatalException(std::exception const &e, bool showStackTrace) {
  if (showStackTrace)
#ifdef STAR_USE_CPPTRACE
    Logger::error("Fatal Exception caught: {}\nCaught at:\n{}",
                  outputException(e, true), captureBacktrace());
#else
    Logger::error("Fatal Exception caught: {}\nCaught at:\n{}",
                  outputException(e, true), outputStack(captureStack()));
#endif
  else
    Logger::error("Fatal Exception caught: {}",
                  outputException(e, showStackTrace));

  std::abort();
}
