#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

#include "Game/GameConfigurator.hpp"
#include "Game/GameConfigurationsCleaner.hpp"
#include "Shapes/ShapesDrawer.hpp"

class Game
{
    private:
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
        const int PADDLE_WIDTH = 100;
        const int PADDLE_HEIGHT = 20;
    
        //Game objects
        float paddleX = SCREEN_WIDTH / 2 - PADDLE_WIDTH / 2;
        float paddleY = SCREEN_HEIGHT - 50;

        SDL_Window* window = nullptr;
        SDL_GLContext context = nullptr;

        GameConfigurator gameConfigurator;
        GameConfigurationsCleaner configurationsCleaner;

        void GameLoop();        
        void Render();
    
    public:
        Game(GameConfigurator gameConfigurator, GameConfigurationsCleaner configurationsCleaner);
        ~Game();
        void Run();   
};

#endif
