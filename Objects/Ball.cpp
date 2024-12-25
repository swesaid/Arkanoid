#include "Ball.hpp"

Ball::Ball()  {};
Ball::~Ball() {};
        
float Ball::getX() const
{
    return _ballX;
}

float Ball::getY() const
{
    return _ballY;
}

float Ball::getDX() const
{
    return _ballDX;
}

float Ball::getDY() const
{
    return _ballDY;
}

int Ball::getSize() const
{
    return _ballSize;
}

void Ball::setX(float ballX)
{
    _ballX = ballX;
}

void Ball::setY(float ballY)
{
    _ballY = ballY;
}

void Ball::setDY(float ballDY)
{
    _ballDY = ballDY;
}

void Ball::setDX(float ballDX)
{
    _ballDX = ballDX;
}

void Ball::Move()
{
    _ballX += _ballDX;
    _ballY += _ballDY;
}
