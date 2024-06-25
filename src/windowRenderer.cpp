#include "windowRenderer.hpp"
#include "inputListener.hpp"
#include "util/loggers.hpp"
#include <SDL_render.h>
#include <SDL_video.h>
#include <SDL_keyboard.h>

// Default Constructor:
Renderer::Renderer(std::string name, i32 width, i32 height, u32 flag)
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
  background_color.red = r;
  background_color.green = g;
  background_color.blue = b;
  background_color.alpha = a;
};
void Renderer::SetBackgroundColor(const color &Color) noexcept {
  background_color.red = Color.red;
  background_color.green = Color.green;
  background_color.blue = Color.blue;
  background_color.alpha = Color.alpha;
}
void Renderer::DisplayWindow() {
  SDL_SetRenderDrawColor(renderer, background_color.red, background_color.green, background_color.blue, background_color.alpha);
  b8 quit = false;
  while (!quit) {
    while (InputListener::ListenEvents() != 0) {
      if (InputListener::GetEventType() == SDL_QUIT) quit = true;
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
}

void Renderer::RemoveWindow() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}
