#include "input.hpp"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_stdinc.h"
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <unordered_map>

namespace SimpleRenderer {
Input::Input() { shouldQuit = false; }

bool Input::getShouldQuit() { return shouldQuit; }

Input &Input::getInstance() {
  static Input instance;
  return instance;
}

std::unordered_map<SDL_Keycode, bool> &Input::getKeysPressed() {
  return keysPressed;
}

std::unordered_map<Uint16, bool> &Input::getModifierKeysPressed() {
  return modifierKeysPressed;
}

bool Input::isKeyPressed(SDL_Keycode key) { return keysPressed[key]; }

bool Input::isModifierKeyPressed(Uint16 key) {
  return modifierKeysPressed[key];
}

glm::vec2 Input::getMousePos() { return glm::vec2(mouseX, mouseY); }

glm::vec2 Input::getLastMousePos() { return glm::vec2(lastMouseX, lastMouseY); }

void Input::processInput(SDL_Event &e) {
  switch (e.type) {
  case SDL_QUIT:
    shouldQuit = true;
    return;
  case SDL_KEYDOWN:
    keysPressed[e.key.keysym.sym] = true;
    break;
  case SDL_KEYUP:
    keysPressed[e.key.keysym.sym] = false;
    break;
  case SDL_MOUSEMOTION:
    lastMouseX = mouseX;
    lastMouseY = mouseY;
    mouseX = e.motion.x;
    mouseY = e.motion.y;
    break;
  default:
    break;
  }
}
} // namespace SimpleRenderer
