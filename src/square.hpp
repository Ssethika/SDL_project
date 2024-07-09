#include <unordered_map>
#include <string>
#include <SDL.h>

enum SQUARECOLOR {
	BLACK,
	LIGHT_BLUE,
	DARK_BLUE,
	YELLOW,
	GREEN,
	ORANGE,
	RED,
	PURPLE,
};

struct Square {
	static std::unordered_map<SQUARECOLOR, SDL_Rect> squareColorPositions; 

	SQUARECOLOR color;
	int x;
	int y;
	bool IsStopped;
};

