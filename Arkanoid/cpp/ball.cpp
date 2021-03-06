#include "./../header/ball.h"
#include <math.h>

Ball::Ball()// : speed(new Vecteur{-2.0, -2.0})
{};

Ball::Ball(Sdl_o_surface img, char p_size, int p_xStart, int p_yStart)// : speed(new Vecteur{-2.0, -2.0})
{
  this->image = img;
  getTexturePosition(p_size);
  this->position = Sdl_o_rectangle(p_xStart,p_yStart,this->positionImage.m_width,this->positionImage.m_height);
};

void Ball::updatePosition()
{
  this->position.m_x += speed[0];
  this->position.m_y += speed[1];
}

float Ball::getX()
{
  return this->position.getRect()->x;
}

float Ball::getY()
{
  return this->position.getRect()->y;
}

void Ball::bounceX()
{
    speed[0] = -speed[0];
}

void Ball::bounceY()
{
    speed[1] = -speed[1];
}

void Ball::bounceYWithAngle(int x1_vault, int x2_vault) //bounce that consider the angle when ball hit the vault
{
  float normalizedIntersection = (((this->position.m_x)-x1_vault) / (x2_vault - x1_vault))*6-3;
  speed[0] = normalizedIntersection;
  bounceY();
}

void Ball::fall()
{
    speed[1] = 0;
}

void Ball::getTexturePosition(char size)
{
  switch (size) {
    case 's':
      this->positionImage = Sdl_o_rectangle(4, 66, 8, 8);
      break;
  }

}

//slow down the ball
void Ball::slowBall()
{
	speed[0] = speed[0] > 0 ? 1.0 : -1.0;
	speed[1] = speed[1] > 0 ? 1.0 : -1.0;
}

void Ball::setSpeed(float x, float y)
{
	speed[0] = x;
	speed[1] = y;
}
