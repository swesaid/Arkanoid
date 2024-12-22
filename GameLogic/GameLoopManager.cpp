#include "GameLoopManager.hpp"
#include <vector>

GameLoopManager::GameLoopManager(Ball ball,
                                 Brick brick,
                                 Paddle paddle,
                                 GraphicsRenderer graphicsRenderer,
                                 BricksRepository bricksRepository,
                                 CollisionHandler collisionHandler) 
{
    _ball = std::move(ball);
    _brick = std::move(brick);
    _paddle = std::move(paddle);
    _graphicsRenderer = std::move(graphicsRenderer);
    _bricksRepository = std::move(bricksRepository);
    _collisionHandler = std::move(collisionHandler);
}
GameLoopManager::~GameLoopManager() {}

void GameLoopManager::Start(int screenWidth, int screenHeight)
{
    _bricksRepository.CreateBricks();
    std::vector<Brick> bricks = _bricksRepository.getBricks();
    int bricksCount = bricks.size();
    
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

        if(bricksCount == 0)
        {
            std::cout << "You won!" << std::endl;
            isRunning = false;
            break;
        }
        if(_ball.getY() > screenHeight )
        {
            std::cout << "You lost :(" << std::endl;
            isRunning = false;
            break;
        }

        if (_paddle.getX() < 0) 
            _paddle.setX(0);
        
        if (_paddle.getX() + _paddle.getWidth() > screenWidth) 
            _paddle.setX(screenWidth - _paddle.getWidth());

        _ball.setX(_ball.getX() + _ball.getDX());
        _ball.setY(_ball.getY() + _ball.getDY());

        _collisionHandler.HandleCollisions(_paddle, _ball, bricks, bricksCount);

        _graphicsRenderer.Render(_paddle, _ball, bricks);
        SDL_Delay(16);
    }
}