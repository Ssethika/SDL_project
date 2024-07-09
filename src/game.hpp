#include "SDL_render.h"
#include "memory"
#include "square.hpp"
#include "vector"
#include "windowRenderer.hpp"
#include <algorithm>
#include <unordered_map>

class Game {
public:
  Game() {}
  Game(const Game &other) = delete;
  void operator=(const Game &other) = delete;
  void GameLoop() { renderer->DisplayWindow(); }
  ~Game() { delete renderer; }
	static bool IsRunning() {return _instance->gameIsRunning;}
  static void Update();
  static Renderer *GetRenderer() { return _instance->renderer; }
	static unsigned int GetSpeed() {return _instance->speed; }
  static void DisplaySquare(Square square);
  static void DisplaySquares(std::vector<Square> squares);
  static void UpdateSquarePosition(std::vector<Square> &squares);
  static void UsePlayerInput(std::vector<Square> &squares);
  static void Run();
  static std::unique_ptr<Game> _instance;
  std::vector<Square> squares = {
      {LIGHT_BLUE, 4, 0}, {RED, 3, 0}, {YELLOW, 3, 1}};

private:
  unsigned int speed = 1000;
  bool gameIsRunning = false;
  Renderer *renderer = new Renderer("application", 700, 1000, SDL_WINDOW_SHOWN);
  SDL_Texture *spriteSheet = renderer->LoadTexture("../assets/TextureFile.jpg");
  int grid[10][20];
};
