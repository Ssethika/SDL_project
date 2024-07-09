#include "square.hpp"

std::unordered_map<SQUARECOLOR, SDL_Rect> Square::squareColorPositions = {
			{LIGHT_BLUE, {0, 0, 100, 100}},
 			{YELLOW, {100, 0, 100, 100}}, 
 			{GREEN, {200, 0, 100, 100}}, 
			{PURPLE, {300, 0, 100, 100}},
			{DARK_BLUE, {400, 0, 100, 100}},
			{ORANGE, {500, 0, 100, 100}},
			{RED, {600, 0, 100, 100}},
			{BLACK, {700, 0, 100, 100}},
};

