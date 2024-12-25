#include "GameResultManager.hpp"


GameResultManager::GameResultManager(std::shared_ptr<TextRenderer> textRenderer):
     _textRenderer(std::move(textRenderer))
{}

void GameResultManager::PrintResult(SDL_Renderer *&renderer, const std::string &message) const
{
    if (!_textRenderer->Initialize())
        throw std::runtime_error("Failed to initialize textRenderer. Error: " + std::string(TTF_GetError()));

    SDL_Color textColor = {255, 255, 255, 255};

    _textRenderer->RenderTextCentered(renderer, message, _screenWidth, _screenHeight, textColor);

    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
}

GameResult GameResultManager::GetResult(int bricksCount, float ballY) const
{
    if (bricksCount == 0)
        return GameResult::Win;
    if (ballY > _screenHeight)
        return GameResult::Lose;

    return GameResult::None;
}

