#include "Paddle.hpp"

Paddle::Paddle() {};
Paddle::~Paddle() {};

int Paddle::getWidth() const
{
    return _paddleWidth;
}

int Paddle::getHeight() const
{
    return _paddleHeight;
}

float Paddle::getX() const
{
    return _paddleX;
}

float Paddle::getY() const
{
    return _paddleY;
}

void Paddle::setX(float paddleX)
{
    _paddleX = paddleX;
}

void Paddle::setWidth(int width)
{
    _paddleWidth = width;
}


