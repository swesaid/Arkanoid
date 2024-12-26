#include "GraphicalPlayerInteraction.hpp"

#include <GameResult.hpp>


GraphicalPlayerInteraction::GraphicalPlayerInteraction(std::shared_ptr<TextRenderer> textRenderer,
                                                       std::shared_ptr<LevelManager> levelManager):
    _textRenderer(std::move(textRenderer)),
    _levelManager(std::move(levelManager))
{}

void GraphicalPlayerInteraction::ShowCurrentLevel(SDL_Renderer *&renderer) const
{
    std::string currentLevel = "Level " + std::to_string(_levelManager->getLevel());
    _textRenderer->RenderTextCentered(renderer, currentLevel, _screenWidth, _screenHeight, _textColor);

    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
}

void GraphicalPlayerInteraction::ShowGameResult(SDL_Renderer *&renderer, const GameResult &result) const
{
    std::string message = result == GameResult::Win ? "You won :)" :
                                                      "You lost :(";

    _textRenderer->RenderTextCentered(renderer, message, _screenWidth, _screenHeight, _textColor);

    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
}




