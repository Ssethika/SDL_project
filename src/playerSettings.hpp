#include <unordered_map>
#include "util/loggers.hpp"
#include <iostream>
#include <vector>

// TODO: create a class that initilize all the keyboard inputs

class PlayerSettings {
private:
	PlayerSettings(){	PlayerSettings::InsertNewKeybinds("jump", (char *)"Space");	};
	static PlayerSettings _instance;
	std::vector<std::string> game_actions = {"jump", "dash"};
public:
	PlayerSettings(const PlayerSettings& other) = delete;
	void operator=(PlayerSettings&) = delete;
	static PlayerSettings& GetInstance() { return _instance;};
	std::unordered_map<std::string, char *> keybindings;
  static void InsertNewKeybinds(std::string key, char* value);
	static char* GetKeybindings(const char* key) { return GetInstance().keybindings[key]; }
};
