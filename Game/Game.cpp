#include "Game.hpp"

Game::Game(GameConfigurator gameConfigurator, 
           GameConfigurationsCleaner configurationsCleaner,
           GraphicsRenderer graphicsRenderer,
           BricksRepository bricksRepository,
           Ball ball,
           Brick brick,
           Paddle paddle)
{
    this -> gameConfigurator = gameConfigurator;
    this -> configurationsCleaner = configurationsCleaner;
    this -> graphicsRenderer = graphicsRenderer;
    this -> bricksRepository = std::move(bricksRepository);
    this -> ball = std::move(ball);
    this -> brick = std::move(brick);
    this -> paddle = std::move(paddle);
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
                    paddle.setX(paddle.getX() - 20);
                else if(event.key.keysym.sym == SDLK_RIGHT)
                    paddle.setX(paddle.getX() + 20);
            }
        }

        if (paddle.getX() < 0) 
            paddle.setX(0);
        
        if (paddle.getX() + paddle.getWidth() > SCREEN_WIDTH) 
            paddle.setX(SCREEN_WIDTH - paddle.getWidth());

        ball.setX(ball.getX() + ball.getDX());
        ball.setY(ball.getY() + ball.getDY());

        graphicsRenderer.Render(paddle, ball, bricksRepository.getBricks());
        SDL_Delay(16);
    }
}