#pragma once

#include <mono/utils/mono-forward.h>

class Mono {
  MonoDomain *domain;

  Mono();
  ~Mono();

public:
  Mono(const Mono &) = delete;
  Mono &operator=(const Mono &) = delete;
  static Mono &get_instance() {
    static Mono instance;
    return instance;
  }
};
