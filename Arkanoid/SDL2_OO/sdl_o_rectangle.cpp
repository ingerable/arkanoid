#include "SDL2-2.0.8/include/SDL.h"

class Sdl_o_rectangle
{
  private:
    int m_x = 0;
    int m_y = 0;
    int m_width = 0;
    int m_height = 0;

 public:
   Sdl_o_rectangle();
   Sdl_o_rectangle(int x1, int y1, int w1, int h1)
   {
     m_x = x1;
     m_y = y1;
     m_width = w1;
     m_height = h1;
   }
};

int main()
{
  return 0;
}
