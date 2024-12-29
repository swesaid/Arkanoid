#include "LevelManager.hpp"


LevelManager::LevelManager():
    _level(1)
{
}

int LevelManager::getLevel() const
{
    return _level;
}

void LevelManager::NextLevel()
{
    _level++;
}

void LevelManager::ResetLevel(Ball &ball, Paddle &paddle)
{
    ball.setX(400);
    ball.setY(300);
    ball.setDX(3.0f);
    ball.setDY(-3.0f);

    paddle.setX((800 - paddle.getWidth()) / 2);
}

void LevelManager::IncreaseDifficulty(Ball &ball, Paddle &paddle)
{
    ball.setDX(ball.getDX() * 1.1f);
    ball.setDY(ball.getDY() * 1.1f);
    paddle.setWidth(paddle.getWidth() * 0.9f);
}




