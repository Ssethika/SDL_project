#include "game.hpp"
#include <random>
#include "SDL_timer.h"

SDL_Rect position = {300, 300, 100, 100};
void Game::Run() {
  int x = 100;
  int y = 100;
  gameIsRunning = true;
  GetRenderer()->RenderBackgroundColor();
  while (gameIsRunning == true) {
    while (InputListener::ListenEvents() != 0) {
      if (InputListener::GetEventType() == SDL_QUIT)
        gameIsRunning = false;
			/* LOG(InputListener::GetCurrentKeyPressed()); */
				GetRenderer()->Clear();
        GetRenderer()->DisplayTexture(squareTexture, &squareDimensions);
				GetRenderer()->DisplayTexture(squareTexture2, &position);
				GetRenderer()->Present();
    }

  }
}

// TODO: Now that we understand how to draw on the screen in SDL. Implement a
// function that creates a rectangle of whatever size we want and to draw it on
// the screen.
