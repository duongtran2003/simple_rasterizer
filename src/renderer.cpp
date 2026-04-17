#include "renderer.hpp"
#include "SDL.h"
#include "SDL_pixels.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include <cstddef>
#include <string>

namespace SimpleRasterizer {
Renderer::Renderer(std::string title, int windowW, int windowH) {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, windowW, windowH, 0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

  framebuffer = SDL_CreateTexture(
      renderer, SDL_PixelFormatEnum::SDL_PIXELFORMAT_RGBA8888,
      SDL_TextureAccess::SDL_TEXTUREACCESS_STREAMING, windowW, windowH);

  isRunning = true;
}

void Renderer::swapFramebuffer() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, framebuffer, NULL, NULL);
  SDL_RenderPresent(renderer);
}

void Renderer::closeWindow() { isRunning = false; }

bool Renderer::isWindowRunning() { return isRunning; }

Renderer::~Renderer() {
  if (framebuffer) {
    SDL_DestroyTexture(framebuffer);
  }
  if (renderer) {
    SDL_DestroyRenderer(renderer);
  }
  if (window) {
    SDL_DestroyWindow(window);
  }

  SDL_Quit();
}
} // namespace SimpleRasterizer
