#ifndef main_H
#define main_H
#include "./SDL2_OO/sdl_o_window.h"
#include "./SDL2_OO/SDL2-2.0.8/include/SDL.h"
#include "./header/ball.h"
int main()
{

  Sdl_o_window	window = Sdl_o_window("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_SHOWN);
  Sdl_o_surface bg = Sdl_o_surface("./bmp/sprites.bmp");
  window.getSurface().setColor(true, 0);
  window.fillWindowWithSurface(bg);

  //ball

  Ball b = Ball(bg, Sdl_o_rectangle(0,128,96,128));
  //window.blitSurfaceOn(b.)

//start
SDL_Event event;
bool quit = false;
while (!quit)
{
  while (!quit && SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        quit = true;
        break;
      default: break;
    }
  }
  window.updateScreen();
  SDL_Delay(40); // 50 fps
}


  return 0;
}

#endif
