#include "Game.hpp"

Game::Game(GameConfigurator gameConfigurator, 
           GameConfigurationsCleaner configurationsCleaner) 
{
    this -> gameConfigurator = gameConfigurator;
    this -> configurationsCleaner = configurationsCleaner;
}

Game::~Game() 
{
    configurationsCleaner.CleanUp(window, context);
}

void Game::Run()
 {
    if (!gameConfigurator.InitializeSDL(window, context, SCREEN_WIDTH, SCREEN_HEIGHT)) 
    {
        std::cerr << "Failed to initialize SDL" << std::endl;
        return;
    }

    if (!gameConfigurator.IntializeOpenGL(SCREEN_WIDTH, SCREEN_HEIGHT)) 
    {
        std::cerr << "Failed to initialize OpenGL" << std::endl;
        configurationsCleaner.CleanUp(window, context);
        return;
    }

    GameLoop();
}

void Game::GameLoop()
{
    bool running = true;
    SDL_Event event;

    while (running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
                running = false;

            else if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_LEFT)
                    paddleX -=20;
                else if(event.key.keysym.sym == SDLK_RIGHT)
                    paddleX += 20;
            }
        }

        if (paddleX < 0) 
            paddleX = 0;
        
        if (paddleX + PADDLE_WIDTH > SCREEN_WIDTH) 
            paddleX = SCREEN_WIDTH - PADDLE_WIDTH;

        Render();
        SDL_Delay(16);
    }
}

void Game::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Drawing paddle
    glColor3f(0.0f, 0.3f, 1.0f);
    ShapesDrawer::DrawRectangle(paddleX, paddleY, PADDLE_WIDTH, PADDLE_HEIGHT);

    SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}