#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>

#include "GameConfigurator.hpp"
#include "GameConfigurationsCleaner.hpp"
#include "GameLoopManager.hpp"

class Game
{
    private:

        const int _screenWidth = 800;
        const int _screenHeight = 600;
        SDL_Window* _window = nullptr;
        SDL_GLContext _context = nullptr;

        //Dependencies
        std::shared_ptr<GameConfigurator> _gameConfigurator;
        std::shared_ptr<GameConfigurationsCleaner> _configurationsCleaner;
        std::unique_ptr<GameLoopManager> _gameLoopManager;

    
    public:

        Game(std::shared_ptr<GameConfigurator> gameConfigurator,
             std::shared_ptr<GameConfigurationsCleaner> configurationsCleaner,
             std::unique_ptr<GameLoopManager> gameLoopManager);

        ~Game();
        void Run() const;
};

#endif
