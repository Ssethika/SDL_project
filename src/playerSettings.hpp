#include "util/loggers.hpp"
#include <unordered_map>
#include <vector>


class PlayerSettings {
public:
  PlayerSettings(const PlayerSettings &other) = delete;

  void operator=(PlayerSettings &) = delete;

  static PlayerSettings &GetInstance() { return _instance; };

  std::unordered_map<std::string, char *> keybindings;

  static void	InsertNewKeybinds(const std::string &key, char *value);

  static inline char *GetKeybindings(const char *key) { return GetInstance().keybindings[key]; }

private:
  PlayerSettings() {
    PlayerSettings::InsertNewKeybinds("jump", (char *)"Space");
  };

  static PlayerSettings _instance;

  std::vector<std::string> game_actions = {"jump", "dash"};
};
