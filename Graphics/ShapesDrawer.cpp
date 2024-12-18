#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "ShapesDrawer.hpp"


void ShapesDrawer::DrawRectangle(float x, float y, float width, float height)
{
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void ShapesDrawer::DrawBricks(const std::vector <Brick> &bricks)
{
    const int BrickWidth = 60;
    const int BrickHeight = 20;

    for (const auto &brick : bricks) 
        if (brick.getState()) 
        {
            glColor3f(1.0f, 0.0f, 0.0f);
            DrawRectangle(brick.getX(), brick.getY(), BrickWidth, BrickHeight);
        }
    
}
