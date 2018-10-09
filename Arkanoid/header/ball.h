#ifndef ball_H // #include guards
#define ball_H
#include "./../SDL2_OO/sdl_o_surface.h"
#include "./../header/gameObject.h"

class Ball: public GameObject
{
  public:
    float speedX = 2;
    float speedY = 2;

  public:
    Ball();
    void updatePosition(); //update the ball position based on speed
    using GameObject::GameObject; //parent constructor
    float getX();
    float getY();
};

#endif
