#include "Application.hpp"

int main(int argc, char **argv) {
  return Sint::runMainApplication(std::make_unique<Sint::Application>());
}
