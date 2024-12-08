#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

#include "Game/GameConfigurator.hpp"
#include "Game/GameConfigurationsCleaner.hpp"
#include "Drawing/ShapesDrawer.hpp"
#include "Data/BricksRepository.hpp"
#include "Objects/Ball.hpp"

class Game
{
    private:
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
            
    
        //Paddle
        const int PADDLE_WIDTH = 100;
        const int PADDLE_HEIGHT = 20;
        float paddleX = SCREEN_WIDTH / 2 - PADDLE_WIDTH / 2;
        float paddleY = SCREEN_HEIGHT - 50;


        SDL_Window* window = nullptr;
        SDL_GLContext context = nullptr;

        //Dependencies
        GameConfigurator gameConfigurator;
        GameConfigurationsCleaner configurationsCleaner;
        BricksRepository bricksRepository;

        //Objects
        Ball ball;
        Brick brick;

        void GameLoop();        
        void Render();
    
    public:
        Game(GameConfigurator gameConfigurator, 
             GameConfigurationsCleaner configurationsCleaner,
             BricksRepository bricksRepository,
             Ball ball,
             Brick brick);
        ~Game();
        void Run();   
};

#endif
