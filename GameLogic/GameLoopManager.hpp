#ifndef GAMELOOPMANAGER_HPP
#define GAMELOOPMANAGER_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Ball.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"
#include "GraphicsRenderer.hpp"
#include "BricksRepository.hpp"
#include "CollisionHandler.hpp"

class GameLoopManager
{
    private:
        
        Ball _ball;
        Brick _brick;
        Paddle _paddle;
        GraphicsRenderer _graphicsRenderer;
        BricksRepository _bricksRepository;
        CollisionHandler _collisionHandler;
    
    public:
        
        GameLoopManager(Ball ball,
                        Brick brick,
                        Paddle paddle,
                        GraphicsRenderer graphicsRenderer,
                        BricksRepository bricksRepository,
                        CollisionHandler collisionHandler);
        
        ~GameLoopManager();
        void Start(int screenWidth);
};


#endif