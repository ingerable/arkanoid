#include "sdl_o_window.h"

Sdl_o_window::Sdl_o_window(char*t,int posX,int posY,int width,int height,int f)
{
  m_title=t;
  m_windowPositionX=posX;
  m_windowPositionY=posY;
  m_windowWidth=width;
  m_windowHeight=height;
  m_flag=f;
  m_pWindow=SDL_CreateWindow(m_title,m_windowPositionX,m_windowPositionY,m_windowWidth,m_windowHeight,m_flag);
  m_win_surf = sdl_o_surface(SDL_GetWindowSurface(m_pWindow));
}
