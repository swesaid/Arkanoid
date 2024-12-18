#include "GameLoopManager.hpp"
#include <vector>

GameLoopManager::GameLoopManager(Ball ball,
                                 Brick brick,
                                 Paddle paddle,
                                 GraphicsRenderer graphicsRenderer,
                                 BricksRepository bricksRepository) 
{
    _ball = std::move(ball);
    _brick = std::move(brick);
    _paddle = std::move(paddle);
    _graphicsRenderer = std::move(graphicsRenderer);
    _bricksRepository = std::move(bricksRepository);
}
GameLoopManager::~GameLoopManager() {}

void GameLoopManager::Start(int screenWidth)
{
    _bricksRepository.CreateBricks();
    
    bool isRunning = true;
    SDL_Event event;

    while (isRunning) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
                isRunning = false;

            else if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_LEFT)
                    _paddle.setX(_paddle.getX() - 20);
                else if(event.key.keysym.sym == SDLK_RIGHT)
                    _paddle.setX(_paddle.getX() + 20);
            }
        }

        if (_paddle.getX() < 0) 
            _paddle.setX(0);
        
        if (_paddle.getX() + _paddle.getWidth() > screenWidth) 
            _paddle.setX(screenWidth - _paddle.getWidth());

        _ball.setX(_ball.getX() + _ball.getDX());
        _ball.setY(_ball.getY() + _ball.getDY());

        _graphicsRenderer.Render(_paddle, _ball, _bricksRepository.getBricks());
        SDL_Delay(16);
    }
}