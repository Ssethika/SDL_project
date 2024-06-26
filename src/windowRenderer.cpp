#include "windowRenderer.hpp"
#include "inputListener.hpp"
#include "util/loggers.hpp"
#include <SDL_render.h>
#include <SDL_video.h>
#include <SDL_keyboard.h>

// Default Constructor:
Renderer::Renderer(const std::string& name, i32 width, i32 height, u32 flag)
    : name(name), width(width), height(height), flag(flag) {
  window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, width, height, flag);
  if (window == NULL) {
    ERROR("Window creation in SDL_CreateWindow has failed");
    SDL_Quit();
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    ERROR(std::string("Renderer could not be created! SDL_Error:") +
          SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
  }
  // TODO: continue on the creation of the renderer class
}
Renderer::~Renderer() {
  RemoveWindow();
  SDL_Quit();
}
void Renderer::SetBackgroundColor(u8 r, u8 g, u8 b, u8 a) noexcept {
  backgroundColor.red = r;
  backgroundColor.green = g;
  backgroundColor.blue = b;
  backgroundColor.alpha = a;
};
void Renderer::SetBackgroundColor(const Color &color) noexcept {
  backgroundColor.red = color.red;
  backgroundColor.green = color.green;
  backgroundColor.blue = color.blue;
  backgroundColor.alpha = color.alpha;
}
void Renderer::RenderDrawColor()const {
	SDL_SetRenderDrawColor(renderer, backgroundColor.red, backgroundColor.green, backgroundColor.blue, backgroundColor.alpha);
}
void Renderer::DisplayWindow() {
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  
}

void Renderer::RemoveWindow() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}
