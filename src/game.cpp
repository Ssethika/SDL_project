#include "game.hpp"

void Game::Run() {
  gameIsRunning = true;
  GetRenderer()->SetBackgroundColor(BLACK);
	GetRenderer()->RenderDrawColor();
  while (gameIsRunning == true) {
    while (InputListener::ListenEvents() != 0) {
      if (InputListener::GetEventType() == SDL_QUIT)
        gameIsRunning = false;
      GetRenderer()->DisplayWindow();
    }
  }
}

// TODO: Now that we understand how to draw on the screen in SDL. Implement a function that creates a rectangle of whatever size we want and to draw it on the screen.
