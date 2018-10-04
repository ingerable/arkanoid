#include <string>
#include <iostream>
#include "sdl_o_rectangle.h"
#ifndef Sdl_o_surface
#define sdl_o_surface

class Sdl_o_surface
{
  private:
    SDL_Surface* m_win_surf = nullptr;

 public:
   Sdl_o_surface();
   Sdl_o_surface(SDL_Surface* m);
   Sdl_o_surface(const char* pathImage);
   SDL_Surface* getSurfPtr();
   int blitSurfaceOn(SDL_Surface &target, SDL_Rect &rectSrc,SDL_Rect &rectTarget);
   void setColor(int flag, Uint32 key);
};

#endif
