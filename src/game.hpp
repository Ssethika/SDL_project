#include "windowRenderer.hpp"
#include "inputListener.hpp"
#include <memory>

class Game{

private:
	bool gameIsRunning = false;
	std::shared_ptr<Renderer> renderer = std::make_shared<Renderer>("application", 1920, 1080, SDL_WINDOW_SHOWN);

public:
	Game(){}; 
	void GameLoop() {
		renderer->DisplayWindow();
	}
	~Game() {;}
	std::shared_ptr<Renderer> GetRenderer() const {
		return renderer;
	}
	void Run() {
		gameIsRunning = true;
		GetRenderer()->RenderDrawColor();
		while (gameIsRunning == true){
			while (InputListener::ListenEvents() != 0) {
				if (InputListener::GetEventType() == SDL_QUIT) gameIsRunning = false;
				GetRenderer()->DisplayWindow();
      }
	  }
  }
};
