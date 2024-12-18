#include "GameLoopManager.hpp"
#include <vector>

GameLoopManager::GameLoopManager(Ball ball,
                                 Brick brick,
                                 Paddle paddle,
                                 GraphicsRenderer graphicsRenderer,
                                 BricksRepository bricksRepository) 
{
    this -> ball = std::move(ball);
    this -> brick = std::move(brick);
    this -> paddle = std::move(paddle);
    this -> graphicsRenderer = std::move(graphicsRenderer);
    this -> bricksRepository = std::move(bricksRepository);
}
GameLoopManager::~GameLoopManager() {}

void GameLoopManager::Start(int screenWidth)
{
    bricksRepository.CreateBricks(brick);
    
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
                    paddle.setX(paddle.getX() - 20);
                else if(event.key.keysym.sym == SDLK_RIGHT)
                    paddle.setX(paddle.getX() + 20);
            }
        }

        if (paddle.getX() < 0) 
            paddle.setX(0);
        
        if (paddle.getX() + paddle.getWidth() > screenWidth) 
            paddle.setX(screenWidth - paddle.getWidth());

        ball.setX(ball.getX() + ball.getDX());
        ball.setY(ball.getY() + ball.getDY());

        graphicsRenderer.Render(paddle, ball, bricksRepository.getBricks());
        SDL_Delay(16);
    }
}