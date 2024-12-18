#ifndef BRICK_HPP
#define BRICK_HPP

class Brick 
{
    private:  
        float _x;
        float _y;
        bool _isActive;

    public:
        Brick();
        Brick(float x,  float y, bool isActive);
        ~Brick();
    
        float getX() const;
        float getY() const;
        bool getState() const;

};

#endif