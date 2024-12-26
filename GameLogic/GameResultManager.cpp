#include "GameResultManager.hpp"


GameResultManager::GameResultManager()
{}

GameResult GameResultManager::GetResult(int bricksCount, float ballY) const
{
    if (bricksCount == 0)
        return GameResult::Win;
    if (ballY > _screenHeight)
        return GameResult::Lose;

    return GameResult::None;
}

