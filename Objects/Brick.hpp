#ifndef BRICK_HPP
#define BRICK_HPP

class Brick 
{
    private:
        int _brickWidth = 60;
        int _brickHeight = 20;  
        int _numberOfRows = 5;
        int _numberOfColumns = 10;  
        float _x;
        float _y;
        bool _isActive;

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