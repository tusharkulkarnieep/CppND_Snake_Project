#include "SDL.h"
#include "mazes.h"
#include <iostream>
#include <vector>

// Maze Constructor

Mazes::Mazes(const std::size_t screen_width, 
             const std::size_t screen_height,
             const std::size_t grid_width, 
             const std::size_t grid_height,
             const int user_level): screen_width(screen_width),
                                    screen_height(screen_height),
                                    grid_width(grid_width),
                                    grid_height(grid_height),
                                    user_level(user_level){}


int Mazes::GetMazeTopEdge()
{ 
  if(user_level == 2) return LEVELTWOTL;
  else if(user_level == 3) return LEVELTHREETL;
  else if(user_level == 4) return LEVELFOURTL;
  else if(user_level == 5) return LEVELFIVETL;
  else return 0;
}
int Mazes::GetMazeBottomEdge()
{
  if(user_level == 2) return LEVELTWOBR;
  else if(user_level == 3) return LEVELTHREEBR;
  else if(user_level == 4) return LEVELFOURBR;
  else if(user_level == 5) return LEVELFIVEBR;
  else return (grid_height - 1);
}
int Mazes::GetMazeLeftEdge()
{
  if(user_level == 2) return LEVELTWOTL;
  else if(user_level == 3) return LEVELTHREETL;
  else if(user_level == 4) return LEVELFOURTL;
  else if(user_level == 5) return LEVELFIVETL;
  else return 0;
}
int Mazes::GetMazeRightEdge()
{
  if(user_level == 2) return LEVELTWOBR;
  else if(user_level == 3) return LEVELTHREEBR;
  else if(user_level == 4) return LEVELFOURBR;
  else if(user_level == 5) return LEVELFIVEBR;
  else return (grid_width - 1);
}

void Mazes::CreateMaze ()
{
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;
    if(user_level == 2)
    { 
      // Top and Bottom boundaries.
      for(int i = 0 ; i < (grid_width) ; i++)
      {
        maze_t.x = i;
        maze_t.y = 0;
        top.push_back(maze_t);

        maze_b.x = i;
        maze_b.y = grid_height-1;
        bottom.push_back(maze_b);
      }
      // Left and Right Boundaries.
      for(int i = 0 ; i < (grid_height) ; i++)
      {
        maze_l.x = 0;
        maze_l.y = i;
        left.push_back(maze_l);

        maze_r.x = grid_width-1;
        maze_r.y = i;
        right.push_back(maze_r);
      }
    }

    else if(user_level == 3)
    {
      for(int i = 0 ; i < (grid_width) ; i++)
      {
        maze_t.x = i;
        maze_t.y = 3;
        top.push_back(maze_t);

        maze_b.x = i;
        maze_b.y = grid_height - 4;
        bottom.push_back(maze_b);
      }
      for(int i = 0 ; i < (grid_height) ; i++)
      {
        maze_l.x = 3;
        maze_l.y = i;
        left.push_back(maze_l);

        maze_r.x = grid_width - 4;
        maze_r.y = i;
        right.push_back(maze_r);
      }
    }

    else if(user_level == 4)
    {
      for(int i = 0 ; i < (grid_width) ; i++)
      {
        maze_t.x = i;
        maze_t.y = 5;
        top.push_back(maze_t);

        maze_b.x = i;
        maze_b.y = grid_height - 6;
        bottom.push_back(maze_b);
      }
      for(int i = 0 ; i < (grid_height) ; i++)
      {
        maze_l.x = 5;
        maze_l.y = i;
        left.push_back(maze_l);

        maze_r.x = grid_width - 6;
        maze_r.y = i;
        right.push_back(maze_r);
      }
    }

    else if(user_level == 5)
    {
      for(int i = 0 ; i < (grid_width) ; i++)
      {
        maze_t.x = i;
        maze_t.y = 6;
        top.push_back(maze_t);

        maze_b.x = i;
        maze_b.y = grid_height - 7;
        bottom.push_back(maze_b);
      }
      for(int i = 0 ; i < (grid_height) ; i++)
      {
        maze_l.x = 6;
        maze_l.y = i;
        left.push_back(maze_l);

        maze_r.x = grid_width - 7;
        maze_r.y = i;
        right.push_back(maze_r);
      }
    }
}