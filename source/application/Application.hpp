#pragma once

#include "Exception.hpp"
#include "Ptr.hpp"
#include "String.hpp"

namespace Sint {

CLASS_Ptr(Application);
CLASS_Ptr(Renderer);

DEF_EXCEPTION(ApplicationException, Exception);

enum class WindowMode { Normal, Maximized, Fullscreen, Borderless };

class Application {
public:
  virtual ~Application() = default;

  /**
   * Called first
   */
  virtual void startup();

  virtual void applicationInit();

  virtual void renderInit(RendererPtr renderer);

  virtual void update();

  virtual void shutdown();
};

int runMainApplication(ApplicationUPtr application);

} // namespace Sint
