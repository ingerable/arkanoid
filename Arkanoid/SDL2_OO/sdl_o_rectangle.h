#ifndef sdl_o_rectangle_h
#define sdl_o_rectangle_h
#include <SDL2/SDL.h>

class Sdl_o_rectangle
{
  public:
    int m_x = 0;
    int m_y = 0;
    int m_width = 0;
    int m_height = 0;
  private:
    SDL_Rect rect;

 public:
   Sdl_o_rectangle();
   Sdl_o_rectangle(int x1, int y1, int w1, int h1);
   SDL_Rect *getRect();
   void setX(int x);
   void setY(int y);
};

#endif
