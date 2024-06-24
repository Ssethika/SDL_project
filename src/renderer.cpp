#include "renderer.hpp"
#include "util/loggers.hpp"
#include <SDL_render.h>

// Default Constructor:
Renderer::Renderer(std::string name, i32 position_x, i32 position_y, i32 width, i32 height, u32 flag)
	: name(name), position_x(position_x), position_y(position_y), width(width), height(height), flag(flag) {
	window = SDL_CreateWindow(name.c_str(), position_x, position_y, width, height, flag);
	if (window == NULL) {
    ERROR("Window creation in SDL_CreateWindow has failed");
    SDL_Quit();
  }
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	// TODO: continue on the creation of the renderer class
}
Renderer::~Renderer(){
	SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
