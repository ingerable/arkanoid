#include "sdl_o_rectangle.h"

Sdl_o_rectangle::Sdl_o_rectangle(int x1, int y1, int w1, int h1)
{
  m_x = x1;
  m_y = y1;
  m_width = w1;
  m_height = h1;
  rect = { m_x, m_y, m_width, m_height };
};

Sdl_o_rectangle::Sdl_o_rectangle()
{
  m_x = 0;
  m_y = 0;
  m_width = 0;
  m_height = 0;
  rect = { m_x, m_y, m_width, m_height };
}

SDL_Rect* Sdl_o_rectangle::getRect()
{
  rect = { m_x, m_y, m_width, m_height };//update rect struct with attribute before returning rect
  return &rect;
}

void Sdl_o_rectangle::setX(int x)
{
  m_x = x;
}


void Sdl_o_rectangle::setY(int y)
{
  m_y = y;
}
