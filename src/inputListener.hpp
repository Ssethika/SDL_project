#include "util/loggers.hpp"
#include "playerSettings.hpp"
#include "util/types.hpp"
#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <asm-generic/errno.h>

// This class will be a singleton so that all parts of the program can have
// access to Inputs that the user makes.
class InputListener {
public:
  InputListener(InputListener &other) = delete;
  void operator=(InputListener &) = delete;
  constexpr static InputListener &GetInstance() { return _instance; }
  static void LogInstance() { LOG(GetInstance().event.type); }
  static i32 ListenEvents() { return SDL_PollEvent(&GetInstance().event); }
  static SDL_Event *GetEvent() { return &GetInstance().event; }
  static u32 GetEventType() { return GetInstance().event.type; }
	static const u8 SetKeyboardState(int* numkeys);
	static const u8 GetKeyboardState() {return GetInstance().currentKeyboardState;}
	static const char * GetCurrentKeyPressed() { return SDL_GetKeyName(InputListener::GetEvent()->key.keysym.sym);}
	static bool KeyboardIsPressed();
	static bool IsActionPressed(const char * action);
	
private:
  InputListener(){};
  b8 listening = true;
  SDL_Event event;
  static InputListener _instance;
	u8 currentKeyboardState;


};
