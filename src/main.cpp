#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "util/loggers.hpp"
#include "util/macros.hpp"
#include "util/types.hpp"

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		ERROR(std::string("SDL failed to init") + SDL_GetError());
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("Application", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	return 0;
}
