#define SDL_MAIN_USE_CALLBACKS 1 /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

/**
 * run at startup
 */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {}
