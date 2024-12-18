#include "Objects/Brick.hpp"

Brick::Brick() {};

Brick::Brick(float x,  float y, bool isActive)
{
    _x = x;
    _y = y;
    _isActive = isActive;
}

Brick::~Brick() {};

int Brick::getWidth() const
{
    return _brickWidth;
}

int Brick::getHeight() const
{
    return _brickHeight;
}

int Brick::getRowsCount() const
{
    return _numberOfRows;
}

int Brick::getColsCount() const
{
    return _numberOfColumns;
}

float Brick::getX() const
{
    return _x;
}

float Brick::getY() const
{
    return _y;
}

bool Brick::getState() const
{
    return _isActive;
}