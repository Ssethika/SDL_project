#include "game.hpp"
#include "SDL_events.h"
#include "SDL_stdinc.h"
#include "SDL_timer.h"
#include "inputListener.hpp"
#include "timer.hpp"
#include "util/loggers.hpp"
#include "util/macros.hpp"
#include <cstdint>
#include <cstdlib>
#include <memory>

void timerCallback() {
  /* Game::_instance->Update(); */
  Game::Update();
}

void Game::Run() {
  Game::_instance->gameIsRunning = true;
  Game::GetRenderer()->RenderBackgroundColor();
  Timer timer = Timer(Game::GetSpeed(), timerCallback);
  timer.start();

  while (Game::IsRunning() == true) {
    InputListener::ListenEvents();
    if (InputListener::GetEventType() == SDL_QUIT)
      _instance->gameIsRunning = false;
    GetRenderer()->Clear();
    UpdateSquarePosition(_instance->squares);

    DisplaySquares(_instance->squares);
    GetRenderer()->Present();
  }
  timer.stop();
}
void Game::Update() {
  for (auto &square : Game::_instance->squares) {
    square.y += 1;
  }
}

void Game::DisplaySquare(Square square) {
  SDL_Rect src = {square.x * 50, square.y * 50, 50, 50};
  SDL_Rect rect_area = Square::squareColorPositions.at(square.color);
  GetRenderer()->DisplayTexture(GetRenderer()->LoadTextureFromSpriteSheet(
                                    _instance->spriteSheet, &rect_area),
                                &src);
}

void Game::DisplaySquares(std::vector<Square> squares) {
  for (auto &square : squares) {
    DisplaySquare(square);
  }
}
void Game::UpdateSquarePosition(std::vector<Square> &squares) {
  for (auto &square : squares) {
    if (InputListener::IsActionPressed("move_left")) {
      if (square.x > 1) square.x -= 1;
    } else if (InputListener::IsActionPressed("move_right")) { // TODO:: Finish this input system
			if (square.x < 20) square.x += 1;
    } else if (InputListener::IsActionPressed("move_down")) {
			if (square.IsStopped == true) square.y += 1;
		}
  }

  /* void Game::UsePlayerInput(std::vector<Square>& squares) { */
}
std::unique_ptr<Game> Game::_instance = std::make_unique<Game>();
