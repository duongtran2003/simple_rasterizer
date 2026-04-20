#pragma once

#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_stdinc.h"
#include <glm/fwd.hpp>
#include <unordered_map>

namespace SimpleRenderer {
class Input {
public:
  static Input &getInstance();
  Input(const Input &) = delete;
  Input &operator=(const Input &) = delete;

  bool getShouldQuit();

  void processInput(SDL_Event &e);

  std::unordered_map<SDL_Keycode, bool> &getKeysPressed();
  std::unordered_map<Uint16, bool> &getModifierKeysPressed();

  bool isKeyPressed(SDL_Keycode key);
  bool isModifierKeyPressed(Uint16 key);

  glm::vec2 getMousePos();
  glm::vec2 getLastMousePos();

private:
  Input();

  std::unordered_map<SDL_Keycode, bool> keysPressed;
  std::unordered_map<Uint16, bool> modifierKeysPressed;

  bool shouldQuit;

  Sint32 mouseX;
  Sint32 mouseY;

  Sint32 lastMouseX;
  Sint32 lastMouseY;
};
} // namespace SimpleRenderer
