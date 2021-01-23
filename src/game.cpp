#include "game.h"
#include <iostream>
#include "SDL.h"

#define CENTER_X (16)
#define CENTER_Y (16)

Game::Game(std::size_t screen_width,
           std::size_t screen_height,
           std::size_t grid_width,
           std::size_t grid_height,
           int maze_top_edge,
           int maze_bottom_edge,
           int maze_left_edge,
           int maze_right_edge,
           int user_level, int user_speed) : snake(grid_width, grid_height),
                                             engine(dev()),
                                             random_w(maze_left_edge, maze_right_edge), // Set maze boundaries as upper and lower limits 
                                             random_h(maze_top_edge, maze_bottom_edge), //to place food within the maze
                                             user_level(user_level),
                                             user_speed(user_speed),
                                             mazes(screen_width, screen_height, grid_width, grid_height, user_level)
{
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  mazes.CreateMaze();
  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, mazes);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count, snake.lives);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y))
    {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::UpdateScore(int *user_level)
{
  switch (*user_level)
  {
  case 1:
    score += 5;
    break;

  case 2:
    score += 10;
    break;

  case 3:
    score += 15;
    break;

  case 4:
    score += 20;
    break;

  case 5:
    score += 30;
    break;

  default:
    break;
  }
}

void Game::Update()
{
  if (!snake.alive)
  {
    //Check if more lives available
    if (GetLives() > 0)
    {
      snake.alive = true;
      snake.lives--;
      // If the snake is dead but still has lives, just erase the body keeping the head and
      // continue playing and set alive to true.
      for (auto const &item : snake.body)
      {
        snake.body.erase(snake.body.begin());
      }
      // Restart form the Center
      snake.head_x = CENTER_X;
      snake.head_y = CENTER_Y;
    }
    else return;
  }
  snake.Update();
  snake.UpdateSpeed(&user_speed);
  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y)
  {
    UpdateScore(&user_level); //score update
    PlaceFood();
    // Grow snake.
    snake.GrowBody();
  }
  SnakeTouchesMaze(&new_x, &new_y);
}

void Game::SnakeTouchesMaze(int *head_x, int *head_y)
{
  // Snake dies if Head touches the Maze Top
  for(auto const &item : mazes.top)
  {
    if (*head_x == item.x && *head_y == item.y) 
    {
      snake.alive = false;
    }
  }
  // Snake dies if Head touches the Maze Bottom
  for(auto const &item : mazes.bottom)
  {
    if (*head_x == item.x && *head_y == item.y) 
    {
      snake.alive = false;
    }
  }
  // Snake dies if Head touches the Maze Left
  for(auto const &item : mazes.left)
  {
    if (*head_x == item.x && *head_y == item.y) 
    {
      snake.alive = false;
    }
  }
  // Snake dies if Head touches the Maze Right
  for(auto const &item : mazes.right)
  {
    if (*head_x == item.x && *head_y == item.y)  
    {
      snake.alive = false;
    }
  }
}
int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
int Game::GetLives() const { return snake.lives; }