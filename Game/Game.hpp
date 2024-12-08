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
#include "Objects/Brick.hpp"
#include "Objects/Paddle.hpp"

class Game
{
    private:
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;

        SDL_Window* window = nullptr;
        SDL_GLContext context = nullptr;

        //Dependencies
        GameConfigurator gameConfigurator;
        GameConfigurationsCleaner configurationsCleaner;
        BricksRepository bricksRepository;

        //Game Objects
        Ball ball;
        Brick brick;
        Paddle paddle;

        void GameLoop();        
        void Render();
    
    public:
        Game(GameConfigurator gameConfigurator, 
             GameConfigurationsCleaner configurationsCleaner,
             BricksRepository bricksRepository,
             Ball ball,
             Brick brick,
             Paddle paddle);

        ~Game();
        void Run();   
};

#endif
