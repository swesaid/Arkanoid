#ifndef PADDLE_HPP
#define PADDLE_HPP

class Paddle
{
    private:
        int _screenWidth = 800;
        int _screenHeight = 600;
        int _paddleWidth = 100;
        int _paddleHeight = 20;
        float _paddleX = _screenWidth / 2 - _paddleWidth / 2;
        float _paddleY = _screenHeight - 50;

    public:
        Paddle();
        ~Paddle();
        int getWidth() const;
        int getHeight() const;
        float getX() const;
        float getY() const;

        void setX(float paddleX); 

        
};


#endif