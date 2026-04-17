#pragma once

#include "SDL_render.h"
#include "SDL_video.h"
#include <string>
namespace SimpleRasterizer {
class Renderer {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *framebuffer;
  bool isRunning;

  ~Renderer();

public:
  inline static constexpr int WIDTH = 800;
  inline static constexpr int HEIGHT = 600;
  inline static std::string TITLE = "Simple Rasterizer";

  Renderer(std::string title = TITLE, int windowW = WIDTH,
           int windowH = HEIGHT);
  void swapFramebuffer();
  void closeWindow();
  bool isWindowRunning();
};
} // namespace SimpleRasterizer
