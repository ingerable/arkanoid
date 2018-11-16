#include "./../header/ball.h"

Ball::Ball(){};

Ball::Ball(Sdl_o_surface img, Sdl_o_rectangle startPos)
{
  this->image = img;
  this->position = startPos;
  getTexturePosition();
};

void Ball::updatePosition()
{
  this->position.m_x += speedX;
  this->position.m_y += speedY;
}

float Ball::getX()
{
  return this->position.getRect()->x;
}

float Ball::getY()
{
  return this->position.getRect()->y;
}

void Ball::getTexturePosition()
{
  this->positionImage = Sdl_o_rectangle( 4,66,8,8 );
}
