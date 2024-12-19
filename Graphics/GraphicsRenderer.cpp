#include "GraphicsRenderer.hpp"

GraphicsRenderer::GraphicsRenderer() {}
GraphicsRenderer::~GraphicsRenderer() {}

void GraphicsRenderer::Render(Paddle paddle, Ball ball, const std::vector <Brick> &bricks)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Drawing paddle
    glColor3f(0.0f, 0.3f, 1.0f);
    ShapesDrawer::DrawRectangle(paddle.getX(), paddle.getY(), paddle.getWidth(), paddle.getHeight());

    //Draw ball
    glColor3f(1.0f, 1.0f, 0.0f);
    // ShapesDrawer::DrawRectangle(ball.getX(), ball.getY(), ball.getSize(), ball.getSize());
    ShapesDrawer::DrawCircle(ball.getX() + ball.getSize() / 2, ball.getY() + ball.getSize() / 2, ball.getSize() / 2, 50);

    ShapesDrawer::DrawBricks(bricks);

    SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}