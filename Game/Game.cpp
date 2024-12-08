#include "Game.hpp"

Game::Game(GameConfigurator gameConfigurator, 
           GameConfigurationsCleaner configurationsCleaner,
           BricksRepository bricksRepository,
           Ball ball,
           Brick brick)
{
    this -> gameConfigurator = gameConfigurator;
    this -> configurationsCleaner = configurationsCleaner;
    this -> bricksRepository = std::move(bricksRepository);
    this -> ball = std::move(ball);
    this -> brick = std::move(brick);
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
    bricksRepository.CreateBricks(brick);
    GameLoop();
}

void Game::GameLoop()
{   
    bool isRunning = true;
    SDL_Event event;

    while (isRunning) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
                isRunning = false;

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

        ball.setX(ball.getX() + ball.getDX());
        ball.setY(ball.getY() + ball.getDY());

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

    //Draw ball
    glColor3f(1.0f, 1.0f, 0.0f);
    ShapesDrawer::DrawRectangle(ball.getX(), ball.getY(), ball.getSize(), ball.getSize());

    ShapesDrawer::DrawBricks(bricksRepository.getBricks(), brick);

    SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}