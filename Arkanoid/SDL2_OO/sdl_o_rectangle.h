#ifndef sdl_o_rectangle_h
#define sdl_o_rectangle_h
#include <SDL2/SDL.h>

class Sdl_o_rectangle
{
  public:
    float m_x = 0;
    float m_y = 0;
    float m_width = 0;
    float m_height = 0;
  private:
    SDL_Rect rect;

 public:
   Sdl_o_rectangle();
   Sdl_o_rectangle(float x1, float y1, float w1, float h1);
   SDL_Rect *getRect();
   void setX(float x);
   void setY(float y);
};

#endif
