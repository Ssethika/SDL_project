#include "game.hpp"
#include "SDL_timer.h"

void Game::Run() {
  int x = 100;
  int y = 100;
  gameIsRunning = true;
  GetRenderer()->RenderBackgroundColor();
  while (gameIsRunning == true) {
    if (InputListener::GetEventType() == SDL_QUIT)
      gameIsRunning = false;
    LOG(InputListener::GetCurrentKeyPressed());
    /* if (InputListener::IsActionPressed("jump")) { */
		GetRenderer()->Clear();
    GetRenderer()->DrawRectangle({x, y}, {100, 100}, WHITE);
    GetRenderer()->DrawRectangle({300, 100}, {100, 100}, WHITE);
		GetRenderer()->Present();
    /* } else { */
    /* GetRenderer()->EraseRectangle({x, y}, {100, 100}); */
    /* GetRenderer()->EraseRectangle({300, 100}, {100, 100}); */
    /* } */
  }
}
/* new stufffffff */
// TODO: Now that we understand how to draw on the screen in SDL. Implement a
// function that creates a rectangle of whatever size we want and to draw it on
// the screen.
