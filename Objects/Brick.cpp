#include "Objects/Brick.hpp"

Brick::Brick(float x,  float y, bool isActive)
{
    this -> x = x;
    this -> y = y;
    this -> isActive = isActive;
}

Brick::~Brick() {};

