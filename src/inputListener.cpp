#include <cstring>
#include "inputListener.hpp"
#include <SDL_events.h>

const u8 InputListener::SetKeyboardState(int *numkeys) {
  _instance.currentKeyboardState = *SDL_GetKeyboardState(numkeys);
  const u8 value = _instance.currentKeyboardState;
  return value;
}
bool InputListener::IsActionPressed(const char *action) {
	bool IsKeyPressed = (!strcmp(GetCurrentKeyPressed(), PlayerSettings::GetKeybindings(action))) && KeyboardIsPressed();
  return IsKeyPressed;
}
bool InputListener::KeyboardIsPressed() {
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  int keyPressed = 0;
  for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
    if (state[i]) {
      keyPressed = 1;
      break;
    }
  }
  return keyPressed;
}
InputListener InputListener::_instance;
