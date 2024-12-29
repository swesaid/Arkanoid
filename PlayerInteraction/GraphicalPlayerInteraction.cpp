#include "GraphicalPlayerInteraction.hpp"


GraphicalPlayerInteraction::GraphicalPlayerInteraction(std::shared_ptr<TextRenderer> textRenderer,
                                                       std::shared_ptr<LevelManager> levelManager):
    _textRenderer(std::move(textRenderer)),
    _levelManager(std::move(levelManager))
{}

void GraphicalPlayerInteraction::ShowCurrentLevel(SDL_Renderer *&renderer) const
{
    std::string currentLevel = "Level " + std::to_string(_levelManager->getLevel());
    DisplayTextWithEventHandling(renderer, currentLevel, 1000);
}

void GraphicalPlayerInteraction::ShowGameResult(SDL_Renderer *&renderer, const GameResult &result) const
{
    std::string message = result == GameResult::Win ? "You won :)" :
                                                      "You lost :(";

    DisplayTextWithEventHandling(renderer, message, 1000);
}

void GraphicalPlayerInteraction::ShowCountdown(SDL_Renderer *&renderer) const
{
    for (int countdown = 5; countdown > 0; countdown--)
        DisplayTextWithEventHandling(renderer, std::to_string(countdown), 1500);
}

void GraphicalPlayerInteraction::ShowMessage(SDL_Renderer *&renderer, const std::string &message) const
{
    DisplayTextWithEventHandling(renderer, message, 1000);
}

void GraphicalPlayerInteraction::DisplayTextWithEventHandling(SDL_Renderer *&renderer, const std::string &message, int durationMs) const
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    Uint32 startTime = SDL_GetTicks();

    _textRenderer->RenderTextCentered(renderer, message, _screenWidth, _screenHeight, _textColor);
    SDL_RenderPresent(renderer);

    SDL_Event event;

    while (SDL_GetTicks() - startTime < durationMs)
        while (SDL_PollEvent(&event))
             if (event.type == SDL_QUIT)
                 exit(0);
}

void GraphicalPlayerInteraction::ShowPauseScreen(SDL_Renderer *&renderer) const
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    _textRenderer->RenderTextCentered(renderer, "Game Paused", _screenWidth, _screenHeight, _textColor);
    SDL_RenderPresent(renderer);
}







