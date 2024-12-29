#include "GameLoopManager.hpp"

#include <GameResultManager.hpp>
#include <vector>

GameLoopManager::GameLoopManager(const Ball &ball,
                                 const Brick &brick,
                                 const Paddle &paddle,
                                 const GraphicsRenderer &graphicsRenderer,
                                 std::unique_ptr<CollisionHandler> collisionHandler,
                                 std::shared_ptr<BricksRepository> bricksRepository,
                                 std::shared_ptr<GameResultManager> gameResultManager,
                                 std::shared_ptr<TextRenderer> textRenderer,
                                 std::shared_ptr<LevelManager> levelManager,
                                 std::shared_ptr<GraphicalPlayerInteraction> graphicalPlayerInteraction)
    :
      _ball(ball),
      _brick(brick),
      _paddle(paddle),
      _graphicsRenderer(graphicsRenderer),
      _collisionHandler(std::move(collisionHandler)),
      _bricksRepository(std::move(bricksRepository)),
      _gameResultManager(std::move(gameResultManager)),
      _textRenderer(std::move(textRenderer)),
      _levelManager(std::move(levelManager)),
      _graphicalPlayerInteraction(std::move(graphicalPlayerInteraction))
{
}

void GameLoopManager::Start(SDL_Renderer *& renderer, int screenWidth, int screenHeight)
{
    bool isGameOver = false;

    while(!isGameOver)
    {
        RunLevel(renderer, screenWidth, screenHeight);
        if (!_shouldMoveToNextLevel)
            isGameOver = true;
    }
}

void GameLoopManager::RunLevel(SDL_Renderer *& renderer, int screenWidth, int screenHeight)
{
    if (!_textRenderer->Initialize())
        throw std::runtime_error("Failed to initialize textRenderer. Error: " + std::string(TTF_GetError()));

    _bricksRepository->CreateBricks();
    std::vector<Brick> bricks = _bricksRepository->getBricks();
    int bricksCount = bricks.size();

    _graphicalPlayerInteraction->ShowCurrentLevel(renderer);
    _graphicalPlayerInteraction -> ShowCountdown(renderer);


    bool isRunning = true;
    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
                _shouldMoveToNextLevel = false;
                break;
            }

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
            _graphicalPlayerInteraction->ShowGameResult(renderer, gameResult);

            if (gameResult == GameResult::Win)
            {
                _levelManager->ResetLevel(_ball, _paddle);
                _levelManager->NextLevel();
                _levelManager->IncreaseDifficulty(_ball, _paddle);
            }
            else
                _shouldMoveToNextLevel = false;

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

