#include "sdl_o_rectangle.h"

Sdl_o_rectangle::Sdl_o_rectangle(float x1, float y1, float w1, float h1)
{
  m_x = x1;
  m_y = y1;
  m_width = w1;
  m_height = h1;
  rect = { static_cast<int>(m_x), static_cast<int>(m_y), static_cast<int>(m_width), static_cast<int>(m_height) };
};

Sdl_o_rectangle::Sdl_o_rectangle()
{
  m_x = 0;
  m_y = 0;
  m_width = 0;
  m_height = 0;
  rect = { static_cast<int>(m_x), static_cast<int>(m_y), static_cast<int>(m_width), static_cast<int>(m_height) };
}

SDL_Rect* Sdl_o_rectangle::getRect()
{
  rect = { static_cast<int>(m_x), static_cast<int>(m_y), static_cast<int>(m_width), static_cast<int>(m_height) };//update rect struct with attribute before returning rect
  return &rect;
}

void Sdl_o_rectangle::setX(float x)
{
  m_x = static_cast<int>(x);
}


void Sdl_o_rectangle::setY(float y)
{
  m_y = static_cast<int>(y);
}
