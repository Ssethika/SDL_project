#include "util/colors.hpp"
#include "util/types.hpp"
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_keyboard.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <string>

// Here is the renderer class

class IRenderer {
private:
  i32 width;
  i32 height;

public:
  virtual void DisplayWindow() = 0;
  virtual void RemoveWindow() = 0;
  virtual SDL_Texture *LoadTexture(const char *file) = 0;
  virtual void DrawRectangle(v2<int> Position, v2<int> Dimension,
                             const Color &color) = 0;
	/* virtual void DrawRectangles() = 0; */
  virtual void Clear() = 0;
  virtual void EraseRectangle(v2<int> Position, v2<int> Dimension) = 0;
	virtual void Present() = 0;
};

class Renderer : public IRenderer {
public:
  Renderer(const std::string &name, i32 width, i32 height, u32 flag);


  Renderer(const Renderer &other) = delete;
  Renderer &operator=(const Renderer &other) = delete;
  ~Renderer();

  // Set background color at runtime.
  void GetBackgroundColor() const;
  void RenderBackgroundColor() const;
  void SetBackgroundColor(u8 r, u8 g, u8 b, u8 a) noexcept;
  void SetBackgroundColor(const Color &color) noexcept;
  Color GetBackGroundColor() noexcept;
	void RendererMulitpleRects() const;

  virtual void DisplayWindow() override;
  virtual void RemoveWindow() override;
  virtual SDL_Texture *LoadTexture(const char *file) override;
  virtual void DrawRectangle(v2<int> position, v2<int> dimension,
                             const Color &color) override;
	/* virtual void DrawRectangles() override; *1/ */
  virtual void EraseRectangle(v2<int> Position, v2<int> Dimension) override;
  virtual void Clear() override;
	virtual void Present() override;

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  std::string name;
  i32 width;
  i32 height;
  u32 flag;
  // default background color.
  Color backgroundColor = BLACK;
};
