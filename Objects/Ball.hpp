#ifndef BALL_HPP
#define BALL_HPP

class Ball
{
    private:
        int SCREEN_WIDTH = 800;
        int SCREEN_HEIGHT = 600;
        
        int BALL_SIZE = 15;
        float ballX = SCREEN_WIDTH / 2;
        float ballY = SCREEN_HEIGHT / 2;
        float ballDX = 3.0f;
        float ballDY = -3.0f;

    public:
        Ball();
        ~Ball();
        
        float getX() const;
        float getY() const;
        float getDX() const;
        float getDY() const;
        int getSize() const;

        void setX(float x);
        void setY(float y);


};


#endif