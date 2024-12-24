#include "GameConfigurator.hpp"

GameConfigurator::GameConfigurator() {}
GameConfigurator::~GameConfigurator() {}


bool GameConfigurator::IsConfigured(SDL_Window *window, SDL_Renderer *&renderer, int width, int height)
{
    return InitializeSDL(window, renderer, width, height);
}

bool GameConfigurator::InitializeSDL(SDL_Window *window, SDL_Renderer *&renderer, int width, int height)
{
     if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    if(TTF_Init() < 0)
    {
        std::cerr << "Failed to initialize SDL_ttf: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width, height,
                                          SDL_WINDOW_SHOWN);
    if (!window) 
    {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
    {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}