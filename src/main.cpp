#include "game.hpp"
/* #include "util/loggers.hpp" */
/* #include "util/macros.hpp" */
/* #include "util/types.hpp" */
#include <SDL_events.h>
#include <SDL_video.h>
#include <csignal>
#include <cstdlib>
#include <memory>
#include <string>

int main(int argc, char *argv[]) {
	Game::_instance->Run();
  return 0;
};

// TODO: Tommorow create the function that enables drawing any sort of object in the screen.


