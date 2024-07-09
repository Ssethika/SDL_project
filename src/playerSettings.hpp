#include "util/loggers.hpp"
#include <map>
#include <vector>

class PlayerSettings {
public:
  PlayerSettings(const PlayerSettings &other) = delete;

  void operator=(PlayerSettings &) = delete;

  static PlayerSettings &GetInstance() { return _instance; };

  std::map<std::string, char *> keybindings;

  static void InsertNewKeybinds(const std::string &key, char *value);

  static inline char *GetKeybindings(const char *key) {
    return GetInstance().keybindings[key];
  }

private:
  PlayerSettings() {
    PlayerSettings::InsertNewKeybinds("move_left", (char *)"Left");
    PlayerSettings::InsertNewKeybinds("move_right", (char *)"Right");
  };

  static PlayerSettings _instance;

  std::vector<std::string> game_actions = {"jump", "dash"};
};
