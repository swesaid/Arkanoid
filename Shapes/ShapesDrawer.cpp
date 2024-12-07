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
