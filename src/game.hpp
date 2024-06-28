
#include "windowRenderer.hpp"
#include "inputListener.hpp"

class Game{

private:
	bool gameIsRunning = false;
	Renderer* renderer = new Renderer("application", 1920, 1080, SDL_WINDOW_SHOWN);

public:
	Game(){} 
	void GameLoop() { renderer->DisplayWindow();}
	~Game() {
		delete renderer;
	}
	inline Renderer* GetRenderer() const { return renderer;}
	void Run(); 
  
};
