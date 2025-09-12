#include "Application.hpp"
#include "Logger.hpp"
#include "String.hpp"
#include "Vector.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

namespace Sint {

class SdlInstance {
public:
  SdlInstance(ApplicationUPtr application) {
    Logger::info("Application: Initializing SDL");
    if (!SDL_Init(0))
      throw ApplicationException(
          strf("Couldn't initialize SDL: {}", SDL_GetError()));

    try {
      Logger::info("Application: startup...");
    } catch (std::exception const &e) {
      throw ApplicationException("Application threw exception during startup",
                                 e);
    }

    Logger::info("Application: Initializing SDL Video");
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO))
      throw ApplicationException(
          strf("Couldn't initialize SDL Video: {}", SDL_GetError()));

    Logger::info("Application: using Video Driver '{}'",
                 SDL_GetCurrentVideoDriver());

    Logger::info("Application: Initializing SDL Controller");
    if (!SDL_InitSubSystem(SDL_INIT_GAMEPAD))
      throw ApplicationException(
          strf("Couldn't initialize SDL Controller: {}", SDL_GetError()));

    Logger::info("Application: Initializing SDL Audio");
    if (!SDL_InitSubSystem(SDL_INIT_AUDIO))
      throw ApplicationException(
          strf("Couldn't initialize SDL Audio: {}", SDL_GetError()));

    Logger::info("Application: using Audio Driver '{}'",
                 SDL_GetCurrentAudioDriver());

    Logger::info("Application: Creating SDL window");
    m_sdlWindow = SDL_CreateWindow(m_windowTitle.c_str(), m_windowSize[0],
                                   m_windowSize[1],
                                   SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
    if (!m_sdlWindow)
      throw ApplicationException::format(
          "Application: Could not create SDL Window: {}", SDL_GetError());
  }

private:
  SDL_Window *m_sdlWindow = nullptr;

  Vec2U m_windowSize = {800, 600};
  WindowMode m_windowMode = WindowMode::Normal;

  String m_windowTitle = "Sint";

  ApplicationUPtr m_application;
};

int runMainApplication(ApplicationUPtr application) {
  try {
    {
      SdlInstance sdlInstance(std::move(application));
      // sdlInstance.run();
    }
    Logger::info("Application: stopped gracefully");
    return 0;
  } catch (std::exception const &e) {
    fatalException(e, true);
  } catch (...) {
    fatalError("Unknown Exception", true);
  }
  return 1;
}

} // namespace Sint
