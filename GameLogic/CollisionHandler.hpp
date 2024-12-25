#ifndef COLLISIONHANDLER_CPP
#define COLLISIONHANDLER_CPP

#include "Ball.hpp"
#include "Paddle.hpp"
#include "BricksRepository.hpp"
#include <vector>

class CollisionHandler
{
    private:
        const int _screenWidth = 800;
        void HandleBallAndBrickCollision(Ball &ball, std::vector<Brick> &bricks, int &bricksCount);
        void HandleBallAndWallCollision(Ball &ball);
        void HandleBallAndPaddleCollision(Ball &ball, Paddle &paddle);

    public:
        CollisionHandler();
        ~CollisionHandler();
        void HandleCollisions(Paddle &paddle, Ball &ball, std::vector<Brick> &bricks, int &bricksCount);
        void HandlePaddleBounds(Paddle &paddle);
};

#endif