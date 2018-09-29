#include <iostream>
#include "SDL2-2.0.8/include/SDL.h"

class Sdl_o_image
{
  private:
    char *m_path;
    SDL_Surface* m_plancheSprites = nullptr;

  public:

    Sdl_o_image(char *p)
    {
      if((p != NULL) && (p[0] == '\0'))
      {
        std::cout<<"invalid path";
      }
      else
      {
          m_path = p;
          m_plancheSprites = SDL_LoadBMP(p);
      }
    }

    void setColorKey(int flag, Uint32 key)
    {
        SDL_SetColorKey(m_plancheSprites, flag, key);  // 0: 00/00/00 noir -> transparent
    }
};
