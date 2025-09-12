#include "Application.hpp"

namespace Sint {

void Application::startup() {}

void Application::applicationInit() {}

void Application::renderInit(RendererPtr renderer) {
  // m_renderer = std::move(renderer);
}

// void Application::windowChanged(WindowMode, Vec2U) {}

// void Application::processInput(InputEvent const &) {}

void Application::update() {}

// unsigned Application::framesSkipped() const { return 0; }

// void Application::render() {}

/*void Application::getAudioData(int16_t *samples, size_t sampleCount) {
  for (size_t i = 0; i < sampleCount; ++i)
    samples[i] = 0;
}*/

void Application::shutdown() {}

} // namespace Sint
