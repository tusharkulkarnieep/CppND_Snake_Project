#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "userio.h"
#include "mazes.h"

// Function to take the input from the User for the Level and Snake Speed.

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Userio uio;
  // Get User Level and Speed
  int kUserLevel = uio.TakeUserLevel();
  int kUserSpeed = uio.TakeUserSpeed();

  Mazes mazes(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, kUserLevel);
  // Get all Maze Boundaries and send to Game class
  int kMazeTopEdge = mazes.GetMazeTopEdge();
  int kMazeBottomEdge = mazes.GetMazeBottomEdge();
  int kMazeLeftEdge = mazes.GetMazeLeftEdge();
  int kMazeRightEdge = mazes.GetMazeRightEdge();
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, kUserLevel, kUserSpeed);
  Controller controller;
  Game game(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, 
            kMazeTopEdge, kMazeBottomEdge, kMazeLeftEdge, kMazeRightEdge, 
            kUserLevel, kUserSpeed);

  game.Run(controller, renderer, kMsPerFrame);

  std::cout << std::endl;
  std::cout << "Game has terminated successfully!\n\n";
  std::cout << "Your Score: " << game.GetScore() << "\n\n";
  std::cout << "Snake Size: " << game.GetSize() << "\n\n";
  return 0;
}