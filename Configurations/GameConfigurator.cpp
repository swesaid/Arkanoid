#include "Configurations/GameConfigurator.hpp"

GameConfigurator::GameConfigurator() {}

GameConfigurator::~GameConfigurator() {}


bool GameConfigurator::IsConfigured(SDL_Window *window, SDL_GLContext context, int width, int height)
{
    return InitializeSDL(window, context, width, height) && 
           IntializeOpenGL(window, context, width, height);
}

bool GameConfigurator::InitializeSDL(SDL_Window *window, SDL_GLContext context, int width, int height)
{
     if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_OPENGL);
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

bool GameConfigurator::IntializeOpenGL(SDL_Window *window, SDL_GLContext context, int width, int height)
{
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) 
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, height, 0);

    return true;
}
