#ifndef ball_H // #include guards
#define ball_H
#include "./../SDL2_OO/sdl_o_surface.h"
#include "./../header/gameObject.h"

class Ball: public GameObject
{
  private:
    float x;
    float y;
    float speedX;
    float speedY;

  public:
    Ball();
    using GameObject::GameObject; //parent constructor
    //Ball(const char *pathImage ,Sdl_o_rectangle imagePosition); //path to the image containing the ball , position in the image (in pixel) of the ball
    //Sdl_o_surface getSurface();
};

#endif
