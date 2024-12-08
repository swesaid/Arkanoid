#ifndef BRICK_HPP
#define BRICK_HPP

class Brick 
{
    private:
        int BRICK_WIDTH = 60;
        int BRICK_HEIGHT = 20;  
        int NUM_ROWS = 5;
        int NUM_COLS = 10;  
        float x;
        float y;
        bool isActive;

    public:
        Brick();
        Brick(float x,  float y, bool isActive);
        ~Brick();
        
        int getWidth() const;
        int getHeight() const;
        int getRowsCount() const;
        int getColsCount() const;
        float getX() const;
        float getY() const;
        bool getState() const;

};

#endif