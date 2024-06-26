#include "game.hpp"
#include "util/loggers.hpp"
#include "util/macros.hpp"
#include "util/types.hpp"
#include <SDL_events.h>
#include <SDL_video.h>
#include <csignal>
#include <cstdlib>
#include <memory>

std::unique_ptr<Game> game = std::make_unique<Game>();

int main(int argc, char *argv[]) {
  game->Run();
  return 0;
};
