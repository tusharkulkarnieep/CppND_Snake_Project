#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "mazes.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height,
           const int user_level, const int user_speed);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, Mazes mazes);
  void UpdateWindowTitle(int score, int fps, int lives);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  const int user_level;
  const int user_speed;
};

#endif