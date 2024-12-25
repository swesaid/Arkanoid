#include "GameLoopManager.hpp"

#include <GameResultManager.hpp>
#include <vector>

GameLoopManager::GameLoopManager(const Ball &ball,
                                 const Brick &brick,
                                 const Paddle &paddle,
                                 const GraphicsRenderer &graphicsRenderer,
                                 std::shared_ptr<BricksRepository> bricksRepository,
                                 std::shared_ptr<GameResultManager> gameResultManager,
                                 std::unique_ptr<CollisionHandler> collisionHandler)
    : _ball(ball),
      _brick(brick),
      _paddle(paddle),
      _graphicsRenderer(graphicsRenderer),
      _bricksRepository(std::move(bricksRepository)),
      _gameResultManager(std::move(gameResultManager)),
      _collisionHandler(std::move(collisionHandler))
{
}

void GameLoopManager::Start(SDL_Renderer *& renderer, int screenWidth, int screenHeight)
{

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

            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_LEFT)
                    _paddle.setX(_paddle.getX() - 20);
                else if (event.key.keysym.sym == SDLK_RIGHT)
                    _paddle.setX(_paddle.getX() + 20);
            }
        }

        GameResult gameResult = _gameResultManager->GetResult(bricksCount, _ball.getY());

        if (gameResult != GameResult::None)
        {
            gameResult == GameResult::Win ? _gameResultManager->PrintResult(renderer, "You won! :)") :
                                            _gameResultManager->PrintResult(renderer, "You lost! :(");
            isRunning = false;
            break;
        }


        _collisionHandler->HandlePaddleBounds(_paddle);

        _ball.Move();

        _collisionHandler->HandleCollisions(_paddle, _ball, bricks, bricksCount);

        _graphicsRenderer.Render(renderer, _paddle, _ball, bricks);
        SDL_Delay(16);
    }
}
