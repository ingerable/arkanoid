#include "sdl_o_window.h"

Sdl_o_window::Sdl_o_window(const char*t ,int posX,int posY,int width,int height,int f)
{
  m_title=t;
  m_windowPositionX=posX;
  m_windowPositionY=posY;
  m_windowWidth=width;
  m_windowHeight=height;
  m_flag=f;
  m_pWindow=SDL_CreateWindow(m_title,m_windowPositionX,m_windowPositionY,m_windowWidth,m_windowHeight,m_flag);
  m_win_surf = Sdl_o_surface(SDL_GetWindowSurface(m_pWindow));
}

void Sdl_o_window::fillWindowWithSurface(Sdl_o_surface surface)
{
  SDL_Rect srcBg = { 0,128, 96,128 };//position de la texture de background dans le fichier
  // remplit le fond
  SDL_Rect dest = { 0,0,0,0 };
  for (int j = 0; j < m_win_surf.getSurfPtr()->h; j+=128)
    for (int i = 0; i < m_win_surf.getSurfPtr()->w; i += 96)
    {
      dest.x = i;
      dest.y = j;

      SDL_BlitSurface(surface.getSurfPtr(), &srcBg, m_win_surf.getSurfPtr(), &dest);
    }
}

Sdl_o_surface Sdl_o_window::getSurface()
{
  return m_win_surf;
}

void Sdl_o_window::updateScreen()
{
  SDL_UpdateWindowSurface(m_pWindow);
}

void Sdl_o_window::drawGameObject(GameObject obj, Sdl_o_rectangle startPosition)
{
  SDL_BlitSurface(obj.image.getSurfPtr(), obj.positionImage.getRect(), m_win_surf.getSurfPtr(), startPosition.getRect());
}
