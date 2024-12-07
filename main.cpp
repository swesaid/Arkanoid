#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "Shapes/ShapesDrawer.hpp"


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int PADDLE_WIDTH = 100;
const int PADDLE_HEIGHT = 20;

//Games objects
float paddleX = SCREEN_WIDTH / 2 - PADDLE_WIDTH / 2;
float paddleY = SCREEN_HEIGHT - 50;


void Render();
void CleanUp(SDL_Window *window, SDL_GLContext context);
bool InitializeSDL(SDL_Window*& window, SDL_GLContext& context, int width, int height);
bool InitializeOpenGL(SDL_Window* window, int width, int height);
void GameLoop();



int main(int argc, char *argv[]) 
{
    SDL_Window* window = nullptr;
    SDL_GLContext context = nullptr;

    if (!InitializeSDL(window, context, SCREEN_WIDTH, SCREEN_HEIGHT))
        return -1;

    if (!InitializeOpenGL(window, SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        CleanUp(window, context);
        return -1;
    }

    GameLoop();

    CleanUp(window, context);
}


void Render() 
{

    glClear(GL_COLOR_BUFFER_BIT);

    // Draw paddle
    glColor3f(0.0f, 0.3f, 1.0f);
    ShapesDrawer::DrawRectangle(paddleX, paddleY, PADDLE_WIDTH, PADDLE_HEIGHT);

    SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}

void CleanUp(SDL_Window *window, SDL_GLContext context)
{
    if (context)
        SDL_GL_DeleteContext(context);
    if (window)
        SDL_DestroyWindow(window);

    SDL_Quit();
}

bool InitializeSDL(SDL_Window*& window, SDL_GLContext& context, int width, int height) 
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

bool InitializeOpenGL(SDL_Window* window, int width, int height) 
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

void GameLoop()
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