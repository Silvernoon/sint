#include "platform.hpp"
#include "Logger.hpp"
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

Mono::Mono() {
  MonoDomain *domain = mono_jit_init("Platform");
  if (!domain) {
    Sint::Logger::error("Failed to initialize Mono runtime.");
    throw;
  }
}

Mono::~Mono() { mono_jit_cleanup(domain); }
