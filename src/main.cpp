#include "SDL_events.h"
#include "SDL_render.h"
#include "renderer.hpp"
#include <cstddef>
#include <glm/ext/vector_float4.hpp>
#include <glm/glm.hpp>

struct Point {
  int x;
  int y;
  glm::vec4 color;
};

void putPixel(SDL_Texture *texture, Point &point);

int main() {
  SimpleRasterizer::Renderer *renderer =
      new SimpleRasterizer::Renderer("My simple rasterizer", 640, 480);

  Point p;
  p.x = 25;
  p.y = 25;
  p.color = glm::vec4(133.0f, 50.0f, 168.0f, 255.0f);

  SDL_Event e;

  while (renderer->isWindowRunning()) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        renderer->closeWindow();
      }
      renderer->swapFramebuffer();
    }
  }

  return 0;
}

void putPixel(SDL_Texture *texture, Point &point) {
  unsigned char *pixels;
  int pitch;
  SDL_LockTexture(texture, NULL, (void **)&pixels, &pitch);
  int pixelStride = 4;

  int pixelLocation = pitch * point.y + pixelStride * point.x;
  pixels[pixelLocation] = (unsigned char)point.color.x;
  pixels[pixelLocation + 1] = (unsigned char)point.color.x;
  pixels[pixelLocation + 2] = (unsigned char)point.color.y;
  pixels[pixelLocation + 3] = (unsigned char)point.color.z;
  pixels[pixelLocation + 4] = (unsigned char)point.color.w;

  SDL_UnlockTexture(texture);
}
