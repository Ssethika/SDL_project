#include "util/loggers.hpp"
#include "util/macros.hpp"
#include "util/types.hpp"
#include "windowRenderer.hpp"
#include "inputListener.hpp"
#include <SDL_events.h>
#include <SDL_video.h>
#include <csignal>
#include <cstdlib>

int main(int argc, char *argv[]) {
  Renderer renderer1 = Renderer("application", 1920, 1080, SDL_WINDOW_SHOWN);
	renderer1.SetBackgroundColor(BLACK);
  renderer1.DisplayWindow();
  return 0;
};
