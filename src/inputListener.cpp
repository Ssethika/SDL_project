
#include "inputListener.hpp"
#include <SDL_events.h>

const u8 InputListener::SetKeyboardState(int *numkeys) {
  _instance.currentKeyboardState = *SDL_GetKeyboardState(numkeys);
  const u8 value = _instance.currentKeyboardState;
  return value;
}
bool InputListener::IsActionPressed(const char *action) {
  return std::string(GetCurrentKeyPressed(*GetEvent())) ==
         std::string(PlayerSettings::GetKeybindings(action));
}
InputListener InputListener::_instance;
