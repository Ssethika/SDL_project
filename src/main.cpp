#include "SDL2/SDL.h"
#include "util/loggers.hpp"
#include "util/macros.hpp"
#include "util/types.hpp"
#include "windowRenderer.hpp"
#include <SDL_video.h>
#include <cstdlib>

int main(int argc, char *argv[]) {
  Renderer renderer1 = Renderer("appliation", 800, 600, SDL_WINDOW_SHOWN);
  renderer1.DisplayWindow();
  return 0;
}
