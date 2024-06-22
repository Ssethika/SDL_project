#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "util/loggers.hpp"
#include "util/macros.hpp"

int main(int argc, char *argv[])
{
	FOR_RANGE(0, 5){
		LOG("HelloWorld");
	}
	LOG(TOSTRING(i));
	return 0;
}
