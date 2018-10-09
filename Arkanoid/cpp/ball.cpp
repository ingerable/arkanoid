#include "./../header/ball.h"

Ball::Ball(){};

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
