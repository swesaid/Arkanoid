#include "CollisionHandler.hpp"


CollisionHandler::CollisionHandler() {}
CollisionHandler::~CollisionHandler() {}

void CollisionHandler::HandleCollisions(Paddle &paddle, Ball &ball, std::vector<Brick> &bricks, int &bricksCount)
{
    HandleBallAndPaddleCollision(ball, paddle);
    HandleBallAndWallCollision(ball);
    HandleBallAndBrickCollision(ball, bricks, bricksCount);
}

void CollisionHandler::HandleBallAndBrickCollision(Ball &ball, std::vector<Brick> &bricks, int &bricksCount)
{
    const int BrickWidth = 60;
    const int BrickHeight = 20;
    
    for (auto &brick : bricks) 
    {
        if (brick.getState() && ball.getX() + ball.getSize() > brick.getX() && 
            ball.getX() < brick.getX() + BrickWidth                         &&
            ball.getY() + ball.getSize() > brick.getY()                     && 
            ball.getY() < brick.getY() + BrickHeight) 
        
        {
            brick.setState(false);
            ball.setDY(-ball.getDY());
            bricksCount--;
            break;
        }
    }
}

void CollisionHandler::HandleBallAndWallCollision(Ball &ball)
{
    if(ball.getX() <= 0 || ball.getX() + ball.getSize() >= _screenWidth)
        ball.setDX(-ball.getDX());
    if(ball.getY() <=0)
        ball.setDY(-ball.getDY());
}

void CollisionHandler::HandleBallAndPaddleCollision(Ball &ball, Paddle &paddle)
{

    if (ball.getX() + ball.getSize() > paddle.getX() && ball.getX() < paddle.getX() + paddle.getWidth() &&
        ball.getY() + ball.getSize() > paddle.getY() && ball.getY() < paddle.getY() + paddle.getHeight()) 
    {
        ball.setDY(-ball.getDY());
        ball.setY(paddle.getY() - ball.getSize());
    }
}

void CollisionHandler::HandlePaddleBounds(Paddle &paddle)
{
    if (paddle.getX() < 0)
        paddle.setX(0);

    if (paddle.getX() + paddle.getWidth() > _screenWidth)
        paddle.setX(_screenWidth - paddle.getWidth());
}
