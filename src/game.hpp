#include "SDL_render.h"
#include "windowRenderer.hpp"
#include "inputListener.hpp"

class Game{
public:
	Game(){} 
	void GameLoop() { renderer->DisplayWindow();}
	~Game() {
		delete renderer;
		SDL_DestroyTexture(spriteSheet);
		SDL_DestroyTexture(squareTexture);
	}
	inline Renderer* GetRenderer() const { return renderer;}
	void Run(); 

private:
	bool gameIsRunning = false;
	Renderer* renderer = new Renderer("application", 1920, 1080, SDL_WINDOW_SHOWN);
	SDL_Texture* spriteSheet = renderer->LoadTexture("../assets/TextureFile.png");
	SDL_Rect squareDimensions = {0, 0, 100, 100};
	SDL_Rect squareDimensions2 = {100, 0, 100, 100};
	SDL_Texture* squareTexture = renderer->LoadTextureFromSpriteSheet(spriteSheet, &squareDimensions);
	SDL_Texture* squareTexture2 = renderer->LoadTextureFromSpriteSheet(spriteSheet, &squareDimensions2);
};
