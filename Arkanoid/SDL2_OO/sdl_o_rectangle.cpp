#include "sdl_o_rectangle.h"

Sdl_o_rectangle();
Sdl_o_rectangle(int x1, int y1, int w1, int h1)
{
  m_x = x1;
  m_y = y1;
  m_width = w1;
  m_height = h1;
  rect = { m_x, m_y, m_width, m_height }
};
SDL_Rect getRect()
{
  return this->rect;
}

int main()
{
  return 0;
}
