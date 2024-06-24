#include "SDL.h"
#include "util/types.hpp"
#include "util/colors.hpp"
#include <string>

// Here is the renderer class 


class Renderer{
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::string name;
  i32 position_x;
  i32 position_y;
  i32 width;
  i32 height;
  u32 flag;
	// default background color.
	color background_color = WHITE;	

public:
  Renderer(std::string name, i32 width, i32 height, u32 flag);
  // We don't people copying a renderer
  Renderer(const Renderer &other) = delete;
  Renderer &operator=(const Renderer &other) = delete;
  ~Renderer();

	// Set background color at runtime.
	void SetBackgroundColor(const u8& r,const u8& g,const u8& b,const u8& a) noexcept;
	void SetBackgroundColor(const color& Color) noexcept;

  void DisplayWindow();
  void RemoveWindow();
};

