#ifndef main_H
#define main_H
#include "./SDL2_OO/sdl_o_window.h"
#include "./header/ball.h"
#include "./header/vault.h"

int main()
{
  Sdl_o_window	window = Sdl_o_window("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_SHOWN);
  Sdl_o_surface bg = Sdl_o_surface("./bmp/sprites.bmp");
  window.getSurface().setColor(true, 0);
  window.fillWindowWithSurface(bg);

  //ball
  Ball b = Ball(bg, Sdl_o_rectangle( 0,64,24,24 ), Sdl_o_rectangle(450,800,4,4));
  bg.setColor(true,0);

  //vault_
  Vault v = Vault(bg , Sdl_o_rectangle(128,0,128,32),Sdl_o_rectangle((window.m_windowWidth/2)-30,window.m_windowHeight-30,30,30));
  bg.setColor(true,0);

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

  b.updatePosition(); //update rectangle attribute of ball
  window.drawGameObject((GameObject) b, b.position); //draw ball object on window
  window.drawGameObject((GameObject) v, v.position);
  window.updateScreen();
  window.fillWindowWithSurface(bg); // redraw the background

  SDL_Delay(10); // 50 fps
}


  return 0;
}

#endif
