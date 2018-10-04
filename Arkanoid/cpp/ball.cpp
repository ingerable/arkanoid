#include "./../header/ball.h"

Ball::Ball(char *pathImage, Sdl_o_rectangle rect)
{
  this->image = Sdl_o_surface(pathImage);
  this->positionImage = rect;
}
