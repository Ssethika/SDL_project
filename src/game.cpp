#include "game.hpp"
#include "SDL_timer.h"

void Game::Run() {
  int x = 100;
  int y = 100;
  gameIsRunning = true;
  GetRenderer()->RenderBackgroundColor();
  while (gameIsRunning == true) {
    while (InputListener::ListenEvents() != 0) {
      if (InputListener::GetEventType() == SDL_QUIT)
        gameIsRunning = false;
			LOG(InputListener::GetCurrentKeyPressed());
      if (InputListener::IsActionPressed("jump")) {
        GetRenderer()->DrawRectangle({x, y}, {100, 100}, WHITE);
        SDL_Delay(50);
      } else {
        GetRenderer()->EraseRectange({x, y}, {100, 100});
      }
    }
  }
}
/* new stufffffff */
// TODO: Now that we understand how to draw on the screen in SDL. Implement a
// function that creates a rectangle of whatever size we want and to draw it on
// the screen.
