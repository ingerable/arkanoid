#ifndef ball_H // #include guards
#define ball_H
#include "./../SDL2_OO/sdl_o_surface.h"
#include "./../header/gameObject.h"
#include "./../Vecteur/expressionDeVecteur.hpp"
#include "./../Vecteur/vecteurs.hpp"

class Ball: public GameObject
{
  public:
    //std::unique_ptr<Vecteur> speed;
		Vecteur speed = {
			baseSpeedX,
			baseSpeedY
		};

    static constexpr float baseSpeedX = 0.0; //base speed if we need to retrieve it
    static constexpr float baseSpeedY = -2.0;

  public:
    Ball();
    Ball(Sdl_o_surface img, char p_size, int p_xStart, int p_yStart);
    void getTexturePosition(char size);
    void updatePosition(); //update the ball position based on speed
    using GameObject::GameObject; //parent constructor
    float getX();
    float getY();
    void bounceX();
    void bounceY();
    void bounceYWithAngle(int x1_vault, int x2_vault);
    void fall();
    void slowBall();
    void setSpeed(float x, float y);
};

#endif
