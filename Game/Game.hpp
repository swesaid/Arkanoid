#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

#include "Configurations/GameConfigurator.hpp"
#include "Configurations/GameConfigurationsCleaner.hpp"
#include "GameLogic/GameLoopManager.hpp"

class Game
{
    private:
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
        SDL_Window* window = nullptr;
        SDL_GLContext context = nullptr;

        //Dependencies
        GameConfigurator _gameConfigurator;
        GameConfigurationsCleaner _configurationsCleaner;
        GameLoopManager _gameLoopManager;

    
    public:
        Game(GameConfigurator gameConfigurator, 
             GameConfigurationsCleaner configurationsCleaner,
             GameLoopManager gameLoopManager);

        ~Game();
        void Run();   
};

#endif
