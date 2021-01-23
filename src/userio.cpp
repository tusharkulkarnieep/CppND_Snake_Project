#include "userio.h"
#include <iostream>

int Userio::TakeUserLevel()
{
  std::cout << std::endl;
  std::cout << "Enter the Level (1 to 5) you want to play.. : ";
  std::cin >> level;
  if(level < 1 || level > 5)
  {
    std::cout << std::endl;
    std::cout << "The Level you entered is Invalid!" << std::endl;
    TakeUserLevel();
  }
  else { return level; }
}

int Userio::TakeUserSpeed()
{
  std::cout << std::endl;
  std::cout << "Enter the speed of the snake (1 to 5) you would like to play with.. : ";
  std::cin >> sspeed;
  if(sspeed < 1 || sspeed > 5)
  {
    std::cout << std::endl;
    std::cout << "The Snake Speed you entered is Invalid!" << std::endl;
    TakeUserSpeed();
  }
  else { return sspeed; } 
}