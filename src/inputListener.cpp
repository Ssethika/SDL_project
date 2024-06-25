#include "inputListener.hpp"
#include <SDL_events.h>

const u8 InputListener::SetKeyboardState(int* numkeys){
		_instance.current_keyboard_state = *SDL_GetKeyboardState(numkeys);
		const u8 value = _instance.current_keyboard_state;
    return value;
	}
InputListener InputListener::_instance;

