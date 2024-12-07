#include "Game.hpp"
#include "../Shapes/ShapesDrawer.hpp"

Game::Game() {}

Game::~Game() 
{
    CleanUp();
}

void Game::Run()
 {
    if (!InitializeSDL()) 
    {
        std::cerr << "Failed to initialize SDL" << std::endl;
        return;
    }

    if (!InitializeOpenGL()) 
    {
        std::cerr << "Failed to initialize OpenGL" << std::endl;
        CleanUp();
        return;
    }

    GameLoop();
}


bool Game::InitializeSDL() 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    if (!window) 
    {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    context = SDL_GL_CreateContext(window);
    if (!context) 
    {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}

bool Game::InitializeOpenGL() 
{
    
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) 
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    return true;
}

void Game::CleanUp()
{
    if (context)
        SDL_GL_DeleteContext(context);
    if (window)
        SDL_DestroyWindow(window);

    SDL_Quit();
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