#include "./../header/game.h"

Game::Game(int sizeX, int sizeY, int mode, char *bg)
{
  m_window = Sdl_o_window("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeX, sizeY, SDL_WINDOW_SHOWN);
  m_bg = Sdl_o_surface(bg);

  //fill the window with the bg
  m_window.getSurface().setColor(true, 0);
  m_window.fillWindowWithSurface(bg);
}
