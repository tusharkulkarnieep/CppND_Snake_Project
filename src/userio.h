#ifndef USERIO_H
#define USERIO_H

#include "game.h"

class Userio 
{
 public:
    int TakeUserLevel(); //Function to take level from the User.
    int TakeUserSpeed(); // Function to take the snake speed from the user.

 private:
    int level;
    int sspeed;
};

#endif