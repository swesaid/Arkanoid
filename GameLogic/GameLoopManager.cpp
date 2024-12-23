#include "GameLoopManager.hpp"
#include <vector>

GameLoopManager::GameLoopManager(const Ball& ball,
                                 const Brick& brick,
                                 const Paddle& paddle,
                                 const GraphicsRenderer& graphicsRenderer,
                                 std::shared_ptr<BricksRepository> bricksRepository,
                                 std::unique_ptr<CollisionHandler> collisionHandler,
                                 std::unique_ptr<TextRenderer>textRenderer)
:
    _ball(ball),
    _brick(brick),
    _paddle(paddle),
    _bricksRepository(bricksRepository),
    _graphicsRenderer(graphicsRenderer),
    _collisionHandler(std::move(collisionHandler)),
    _textRenderer(std::move(textRenderer))
{}


void GameLoopManager::Start(int screenWidth, int screenHeight)
{
    if(!_textRenderer->Initialize())
    {
        std::cerr << "Could not load the font" << TTF_GetError() << std::endl;
        return;
    }

    _bricksRepository->CreateBricks();
    std::vector<Brick> bricks = _bricksRepository->getBricks();
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

        _collisionHandler->HandleCollisions(_paddle, _ball, bricks, bricksCount);

        _graphicsRenderer.Render(_paddle, _ball, bricks);
        SDL_Delay(16);
    }
}