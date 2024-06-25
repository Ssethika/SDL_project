#include "playerSettings.hpp"
#include "util/algorithms.hpp"

void PlayerSettings::InsertNewKeybinds(std::string key, char* value) {
	for (const auto& pair : GetInstance().keybindings){
		if (pair.second == value) {
			WARN("There is already a keybinding for this a action.");
		}
	}
	if (IsStringInVector(key, GetInstance().game_actions)){
		GetInstance().game_actions.push_back(key);
	}
  GetInstance().keybindings[key] = value;
}

PlayerSettings PlayerSettings::_instance;

// Initilize default keybindings
