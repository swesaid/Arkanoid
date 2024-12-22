#include "Brick.hpp"

Brick::Brick() {};

Brick::Brick(float x,  float y, bool isActive)
{
    _x = x;
    _y = y;
    _isActive = isActive;
}

Brick::~Brick() {}

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

void Brick::setState(bool state)
{
    _isActive = state;
}