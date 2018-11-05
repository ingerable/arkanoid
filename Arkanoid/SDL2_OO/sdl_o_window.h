#include <string>
#include <iostream>
#ifndef sdl_o_window
#define sdl_o_window
#include "./SDL2-2.0.8/include/SDL.h"
#include "sdl_o_surface.h"
#include "./../header/gameObject.h"


class Sdl_o_window
{
public:
    SDL_Window* m_pWindow = nullptr;
    Sdl_o_surface m_win_surf;
    const char *m_title;
    int m_windowPositionX;
    int m_windowPositionY;
    int m_windowWidth;
    int m_windowHeight;
    Uint32 m_flag;

 public:
   Sdl_o_window();
   Sdl_o_window(const char *t, int posX, int posY, int width, int height, int f);
   void fillWindowWithSurface(Sdl_o_surface surface, Sdl_o_rectangle borders, Sdl_o_rectangle srcBg);
   void drawGameObject(GameObject obj, Sdl_o_rectangle startPosition);
   void updateScreen();
   Sdl_o_surface getSurface();
};

#endif
