#include "SDL.h"
#include "util/colors.hpp"
#include "util/types.hpp"
#include <string>

// Here is the renderer class

class IRenderer {
private:
  i32 width;
  i32 height;

public:
  virtual void DisplayWindow() = 0;
  virtual void RemoveWindow() = 0;
};

class Renderer : public IRenderer {
public:
  Renderer(const std::string& name, i32 width, i32 height, u32 flag);

  Renderer(const Renderer &other) = delete;
  Renderer &operator=(const Renderer &other) = delete;
  ~Renderer();

  // Set background color at runtime.
	void RenderDrawColor() const;
  void SetBackgroundColor(u8 r, u8 g, u8 b, u8 a) noexcept;
  void SetBackgroundColor(const Color &color) noexcept;
	Color GetBackGroundColor() noexcept;

  virtual void DisplayWindow() override;
  virtual void RemoveWindow() override;

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::string name;
  i32 width;
  i32 height;
  u32 flag;
  // default background color.
  Color backgroundColor = WHITE;

};
