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
