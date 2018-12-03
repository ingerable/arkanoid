#ifndef ball_H // #include guards
#define ball_H
#include "./../SDL2_OO/sdl_o_surface.h"
//#include "./../Vecteur/vecteurs.hpp"
#include "./../header/gameObject.h"
//#include <memory>

class Ball: public GameObject
{
  public:
    //std::unique_ptr<Vecteur> speed;
    float speedX = -2.5;
    float speedY = -2.5;

  public:
    Ball();
    Ball(Sdl_o_surface img, Sdl_o_rectangle startPos);
    void getTexturePosition();
    void updatePosition(); //update the ball position based on speed
    using GameObject::GameObject; //parent constructor
    float getX();
    float getY();
    void bounceX();
    void bounceY();
    void fall();
};

#endif
