#include "Game.hpp"

Game::Game(GameConfigurator gameConfigurator, 
           GameConfigurationsCleaner configurationsCleaner,
           BricksRepository bricksRepository) 
{
    this -> gameConfigurator = gameConfigurator;
    this -> configurationsCleaner = configurationsCleaner;
    this -> bricksRepository = bricksRepository;
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
    bricksRepository.CreateBricks(NUM_ROWS, NUM_COLS, BRICK_WIDTH, BRICK_HEIGHT);
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

        ballX += ballDX;
        ballY += ballDY;


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
    ShapesDrawer::DrawRectangle(ballX, ballY, BALL_SIZE, BALL_SIZE);

    ShapesDrawer::DrawBricks(bricksRepository.getBricks(), BRICK_WIDTH, BRICK_HEIGHT);

    SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}