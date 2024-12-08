#ifndef BRICK_HPP
#define BRICK_HPP

struct Brick 
{
    float x;
    float y;
    bool isActive;

    Brick(float x,  float y, bool isActive);
    ~Brick();

};

#endif