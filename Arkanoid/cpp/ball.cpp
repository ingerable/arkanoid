#include "./../header/ball.h"

Ball::Ball()// : speed(new Vecteur{-2.0, -2.0})
{};

Ball::Ball(Sdl_o_surface img, Sdl_o_rectangle startPos)// : speed(new Vecteur{-2.0, -2.0})
{
  this->image = img;
  this->position = startPos;
  getTexturePosition();
};

void Ball::updatePosition()
{
  this->position.m_x += speed[0];
  this->position.m_y += speed[1];
  //this->position.m_x += speedX;
  //this->position.m_y += speedY;
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
    //speedX = -speedX;
}

void Ball::bounceY()
{
    speed[1] = -speed[1];
    //speedY = -speedY;
}

void Ball::fall()
{
    speed[1] = 0;
    //speedY = 0;
}

void Ball::getTexturePosition()
{
  this->positionImage = Sdl_o_rectangle(4, 66, 8, 8);
}

//slow down the ball
void Ball::slowBall()
{
	speed[0] = speed[0] >= 0 ? (speed[0]-1.0) : (speed[0]+1.0);
	speed[1] = speed[1] >= 0 ? (speed[1]-1.0) : (speed[1]+1.0);
  //this->speedX = speedX >= 0 ? (speedX-1.0) : (speedX+1.0);
  //this->speedY = speedY >= 0 ? (speedY-1.0) : (speedY+1.0);
}

void Ball::setSpeed(float x, float y)
{
	speed[0] = x;
	speed[1] = y;
  //this->speedX = x;
  //this->speedY = y;
}
