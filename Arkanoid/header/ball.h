#ifndef ball_H // #include guards
#define ball_H
#include "./../SDL2_OO/sdl_o_surface.h"
#include "./../header/gameObject.h"

class Ball: public GameObject
{
  public:
    //std::unique_ptr<Vecteur> speed;
    float speedX = -2.0;
    float speedY = -2.0;

    const float baseSpeedX = -2.0; //base speed if we need to retrieve it
    const float baseSpeedY = -2.0;

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
    void slowBall();
    void setSpeed(float x, float y);
};

#endif
