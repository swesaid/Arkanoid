#include "Objects/Brick.hpp"

Brick::Brick() {};

Brick::Brick(float x,  float y, bool isActive)
{
    this -> x = x;
    this -> y = y;
    this -> isActive = isActive;
}

Brick::~Brick() {};

int Brick::getWidth() const
{
    return BRICK_WIDTH;
}

int Brick::getHeight() const
{
    return BRICK_HEIGHT;
}

int Brick::getRowsCount() const
{
    return NUM_ROWS;
}

int Brick::getColsCount() const
{
    return NUM_COLS;
}

float Brick::getX() const
{
    return x;
}

float Brick::getY() const
{
    return y;
}

bool Brick::getState() const
{
    return isActive;
}