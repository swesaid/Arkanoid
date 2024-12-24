#include "GameConfigurationsCleaner.hpp"

GameConfigurationsCleaner::GameConfigurationsCleaner() {};
GameConfigurationsCleaner::~GameConfigurationsCleaner() {};

void GameConfigurationsCleaner::CleanUp(SDL_Window *window, SDL_Renderer *& renderer)
{
    if (renderer != nullptr)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    TTF_Quit();
    SDL_Quit();
}