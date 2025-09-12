#include "String.hpp"
#include <exception>
#include <functional>

using std::function;

namespace Sint {
class Exception : public std::exception {
public:
  template <typename... Args>
  static Exception format(StringView str, Args const &...args);

  Exception() noexcept;
  virtual ~Exception() noexcept;

  explicit Exception(std::string message, bool genStackTrace = true) noexcept;
  explicit Exception(std::exception const &cause) noexcept;
  Exception(std::string message, std::exception const &cause) noexcept;

  virtual char const *what() const noexcept override;

  // If the given exception is really StarException, then this will call
  // StarException::printException, otherwise just prints std::exception::what.
  friend void printException(std::ostream &os, std::exception const &e,
                             bool fullStacktrace);
  friend std::string printException(std::exception const &e,
                                    bool fullStacktrace);
  /* friend OutputProxy outputException(std::exception const &e,
                                      bool fullStacktrace);
*/

protected:
  Exception(char const *type, std::string message,
            bool genStackTrace = true) noexcept;
  Exception(char const *type, std::string message,
            std::exception const &cause) noexcept;

private:
  // Takes the ostream to print to, whether to print the full stacktrace.  Must
  // not bind 'this', may outlive the exception in the case of chained
  // exception causes.
  function<void(std::ostream &, bool)> m_printException;

  // m_printException will be called without the stack-trace to print
  // m_whatBuffer, if the what() method is invoked.
  mutable std::string m_whatBuffer;
};

void printException(std::ostream &os, std::exception const &e,
                    bool fullStacktrace);
std::string printException(std::exception const &e, bool fullStacktrace);
// OutputProxy outputException(std::exception const &e, bool fullStacktrace);

void printStack(char const *message);

// Log error and stack-trace and possibly show a dialog box if available, then
// abort.
void fatalError(char const *message, bool showStackTrace);
void fatalException(std::exception const &e, bool showStackTrace);

#define DEF_EXCEPTION(ClassName, BaseName)                                     \
  class ClassName : public BaseName {                                          \
  public:                                                                      \
    template <typename... Args>                                                \
    static ClassName format(StringView str, Args const &...args) {             \
      return ClassName(strf(str, args...));                                    \
    }                                                                          \
    ClassName() : BaseName(#ClassName, std::string()) {}                       \
    explicit ClassName(std::string message, bool genStackTrace = true)         \
        : BaseName(#ClassName, std::move(message), genStackTrace) {}           \
    explicit ClassName(std::exception const &cause)                            \
        : BaseName(#ClassName, std::string(), cause) {}                        \
    ClassName(std::string message, std::exception const &cause)                \
        : BaseName(#ClassName, std::move(message), cause) {}                   \
                                                                               \
  protected:                                                                   \
    ClassName(char const *type, std::string message,                           \
              bool genStackTrace = true)                                       \
        : BaseName(type, std::move(message), genStackTrace) {}                 \
    ClassName(char const *type, std::string message,                           \
              std::exception const &cause)                                     \
        : BaseName(type, std::move(message), cause) {}                         \
  }

template <typename... Args>
Exception Exception::format(StringView str, Args const &...args) {
  return Exception(strf(str, args...));
}

} // namespace Sint
