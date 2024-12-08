#include "Objects/Ball.hpp"

Ball::Ball()  {};
Ball::~Ball() {};
        
float Ball::getX() const
{
    return ballX;
}

float Ball::getY() const
{
    return ballY;
}

float Ball::getDX() const
{
    return ballDX;
}

float Ball::getDY() const
{
    return ballDY;
}

int Ball::getSize() const
{
    return BALL_SIZE;
}

void Ball::setX(float x)
{
    ballX = x;
}

void Ball::setY(float y)
{
    ballY = y;
}