#include <string>
#include <iostream>
#include "./SDL2-2.0.8/include/SDL.h"
#include "sdl_o_surface.h"
#ifndef sdl_o_window
#define sdl_o_window

class Sdl_o_window
{
  private:
    SDL_Window* m_pWindow = nullptr;
    Sdl_o_surface m_win_surf;
    char *m_title;
    int m_windowPositionX;
    int m_windowPositionY;
    int m_windowWidth;
    int m_windowHeight;
    Uint32 m_flag;

 public:
   Sdl_o_window(char *t, int posX, int posY, int width, int height, int f);
};

#endif
