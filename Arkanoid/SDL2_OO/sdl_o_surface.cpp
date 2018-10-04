#include "sdl_o_surface.h"

Sdl_o_surface::Sdl_o_surface(){};

Sdl_o_surface::Sdl_o_surface(SDL_Surface* m)
{
  m_win_surf = m;
}

Sdl_o_surface::Sdl_o_surface(const char* pathImage)
{
  m_win_surf = SDL_LoadBMP(pathImage);
}

 SDL_Surface* Sdl_o_surface::getSurfPtr()
 {
   return m_win_surf;
 }

 // copy rectSrc from current surface to rectTarget on target surface
int Sdl_o_surface::blitSurfaceOn(SDL_Surface &target, SDL_Rect &rectSrc,SDL_Rect &rectTarget)
{
  SDL_BlitSurface(m_win_surf, &rectSrc, &target, &rectTarget);
}


void Sdl_o_surface::setColor(int flag, Uint32 key)
{
  SDL_SetColorKey(m_win_surf, flag, key);
}
