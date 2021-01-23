#ifndef MAZES_H
#define MAZES_H

#include "SDL.h"
#include <vector>

// Setting Maze Boundaries for placing food inside the maze according to the user level
#define LEVELTWOTL (2)      
#define LEVELTWOBR (29)
#define LEVELTHREETL (4)
#define LEVELTHREEBR (27)
#define LEVELFOURTL (6)
#define LEVELFOURBR (25)
#define LEVELFIVETL (8)
#define LEVELFIVEBR (23)

class Mazes 
{
    public:
        Mazes(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height,
           const int user_level);

        //Functions to return the boundaries for all the maze parts.
        int GetMazeTopEdge();
        int GetMazeBottomEdge();
        int GetMazeLeftEdge();
        int GetMazeRightEdge();
        
        //Function to create the Maze according to user level
        void CreateMaze ();

        // SDL_Point vectors to collect all the points on each maze boundary
        std::vector<SDL_Point> top, bottom, left, right;

    private:
        SDL_Rect block;
        SDL_Point maze_t, maze_l, maze_r, maze_b;
        const std::size_t screen_width;
        const std::size_t screen_height;
        const std::size_t grid_width;
        const std::size_t grid_height;
        
        const int user_level;
};

#endif