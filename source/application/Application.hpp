#pragma once

#include <string>

namespace Sint {

enum class WindowMode { Normal, Maximized, Fullscreen, Borderless };

class Application {
public:
  virtual ~Application() = default;

  /**
   * Called first
   */
  virtual void startup(std::string const &args);

  virtual void applicationInit();

  virtual void update();
};

} // namespace Sint
