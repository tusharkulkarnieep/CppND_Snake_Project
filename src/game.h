#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "mazes.h"

class Game {
 public:
  Game(std::size_t screen_width, 
       std::size_t screen_height, 
       std::size_t grid_width, 
       std::size_t grid_height, 
       int maze_top_edge,
       int maze_bottom_edge,
       int maze_left_edge,
       int maze_right_edge,
       int user_level, 
       int user_speed);
  
  void Run(Controller const &controller, Renderer &renderer,std::size_t target_frame_duration);
  

  void UpdateScore(int *user_level);  // Update score depending on the user level
  int GetScore() const;
  int GetSize() const;
  int GetLives() const;               // Function to get lives available.
  void SnakeTouchesMaze(int *head_x, int *head_y); // Function to check if the snake touchecs the maze
                                                   // Takes current head x and y as arguments.

 private:
  Snake snake;
  Mazes mazes;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  int user_level;
  int user_speed;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif