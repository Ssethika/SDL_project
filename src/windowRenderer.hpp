#include "SDL.h"
#include "util/types.hpp"
#include <string>
// Primary class that handles the renderer

class Renderer {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::string name;
  i32 position_x;
  i32 position_y;
  i32 width;
  i32 height;
  u32 flag;
	i32 background_color;

public:
  Renderer(std::string name, i32 width, i32 height, u32 flag);
  // We don't people copying a renderer
  Renderer(const Renderer &other) = delete;
  Renderer &operator=(const Renderer &other) = delete;
  ~Renderer();
  void DisplayWindow();
  void RemoveWindow();
};
