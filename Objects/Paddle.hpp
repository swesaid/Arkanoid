#ifndef PADDLE_HPP
#define PADDLE_HPP

class Paddle
{
    private:
        int SCREEN_WIDTH = 800;
        int SCREEN_HEIGHT = 600;
        int PADDLE_WIDTH = 100;
        int PADDLE_HEIGHT = 20;
        float paddleX = SCREEN_WIDTH / 2 - PADDLE_WIDTH / 2;
        float paddleY = SCREEN_HEIGHT - 50;

    public:
        Paddle();
        ~Paddle();
        int getWidth() const;
        int getHeight() const;
        float getX() const;
        float getY() const;

        void setX(float x); 

        
};


#endif