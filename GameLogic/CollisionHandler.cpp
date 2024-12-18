#include "CollisionHandler.hpp"


CollisionHandler::CollisionHandler() {}
CollisionHandler::~CollisionHandler() {}

void CollisionHandler::HandleCollisions(Paddle &paddle, Ball &ball, std::vector<Brick> &bricks)
{
    HandleBallAndWallCollision(ball);
    HandleBallAndBrickCollision(ball, bricks);
}

void CollisionHandler::HandleBallAndBrickCollision(Ball &ball, std::vector<Brick> &bricks)
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
            break;
        }
    }
}

void CollisionHandler::HandleBallAndWallCollision(Ball &ball)
{
    const int ScreenWidth = 800;
    
    if(ball.getX() <= 0 || ball.getX() + ball.getSize() >= ScreenWidth)
        ball.setDX(-ball.getDX());
    if(ball.getY() <=0)
        ball.setDY(-ball.getDY());
}