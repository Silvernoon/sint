#include <iostream>
#include <steam/steam_api.h>

int main(int, char **) {
  std::cout << "Hello, from sint!" << std::endl;

  if (SteamAPI_Init()) {
    std::cout << "Steam Yes!" << std::endl;
  }
}
