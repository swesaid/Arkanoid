#include "Paddle.hpp"

Paddle::Paddle() {};
Paddle::~Paddle() {};

int Paddle::getWidth() const
{
    return PADDLE_WIDTH;
}

int Paddle::getHeight() const
{
    return PADDLE_HEIGHT;
}

float Paddle::getX() const
{
    return paddleX;
}

float Paddle::getY() const
{
    return paddleY;
}

void Paddle::setX(float x)
{
    paddleX = x;
}

