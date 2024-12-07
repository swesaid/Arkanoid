#include "Game/GameConfigurationsCleaner.hpp"

GameConfigurationsCleaner::GameConfigurationsCleaner() {};
GameConfigurationsCleaner::~GameConfigurationsCleaner() {};

void GameConfigurationsCleaner::CleanUp(SDL_Window *window, SDL_GLContext context)
{
    if (context)
        SDL_GL_DeleteContext(context);
    if (window)
        SDL_DestroyWindow(window);

    SDL_Quit();
}