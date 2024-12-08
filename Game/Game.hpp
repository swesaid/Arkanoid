#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

#include "Game/GameConfigurator.hpp"
#include "Game/GameConfigurationsCleaner.hpp"
#include "Shapes/ShapesDrawer.hpp"
#include "Data/BricksRepository.hpp"

class Game
{
    private:
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
        
        //Bricks
        const int BRICK_WIDTH = 60;
        const int BRICK_HEIGHT = 20;  
        const int NUM_ROWS = 5;
        const int NUM_COLS = 10;      
    
        //Paddle
        const int PADDLE_WIDTH = 100;
        const int PADDLE_HEIGHT = 20;
        float paddleX = SCREEN_WIDTH / 2 - PADDLE_WIDTH / 2;
        float paddleY = SCREEN_HEIGHT - 50;

        //Ball
        const int BALL_SIZE = 15;
        float ballX = SCREEN_WIDTH / 2;
        float ballY = SCREEN_HEIGHT / 2;
        float ballDX = 3.0f;
        float ballDY = -3.0f;


        SDL_Window* window = nullptr;
        SDL_GLContext context = nullptr;

        //Dependencies
        GameConfigurator gameConfigurator;
        GameConfigurationsCleaner configurationsCleaner;
        BricksRepository bricksRepository;

        void GameLoop();        
        void Render();
    
    public:
        Game(GameConfigurator gameConfigurator, GameConfigurationsCleaner configurationsCleaner);
        ~Game();
        void Run();   
};

#endif
