#include <string>
#include <iostream>
#include "SDL2-2.0.8/include/SDL.h"

class Sdl_o_window
{
  private:
    SDL_Window* m_pWindow = nullptr;
    SDL_Surface* m_win_surf = nullptr;
    char *m_title;
    int m_windowPositionX;
    int m_windowPositionY;
    int m_windowWidth;
    int m_windowHeight;
    Uint32 m_flag;


 public:
   Sdl_o_window(char *t, int posX, int posY, int width, int height, int f)
   {
     m_title = t;
     m_windowPositionX = posX;
     m_windowPositionY = posY;
     m_windowWidth = width;
     m_windowHeight = height;
     m_flag = f;
     m_pWindow = SDL_CreateWindow(m_title, m_windowPositionX, m_windowPositionY, m_windowWidth, m_windowHeight, m_flag);
     m_win_surf = SDL_GetWindowSurface(m_pWindow);
   }
};
