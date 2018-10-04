#include "./../SDL2_OO/sdl_o_surface.h"

class Ball
{
  private:
    float x;
    float y;
    float speedX;
    float speedY;
    Sdl_o_surface image;
    Sdl_o_rectangle positionImage;

  public:
    Ball(char *pathImage,Sdl_o_rectangle imagePosition); //path to the image containing the ball , position in the image (in pixel) of the ball

};
