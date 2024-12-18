#ifndef BALL_HPP
#define BALL_HPP

class Ball
{
    private:
        int _screenWidth = 800;
        int _screenHeight = 600;
        
        int _ballSize = 15;
        float _ballX = _screenWidth / 2;
        float _ballY = _screenHeight / 2;
        float _ballDX = 3.0f;
        float _ballDY = -3.0f;

    public:
        Ball();
        ~Ball();
        
        float getX() const;
        float getY() const;
        float getDX() const;
        float getDY() const;
        int getSize() const;

        void setX(float ballX);
        void setY(float ballY);
        void setDY(float ballDY);


};


#endif