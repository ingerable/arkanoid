#pragma once
#include "./../SDL2_OO/sdl_o_rectangle.h"
#include "./../SDL2_OO/sdl_o_surface.h"

class GameObject
{
  public:
    Sdl_o_surface image;
    Sdl_o_rectangle positionImage;

  public:
    GameObject();
    GameObject(Sdl_o_surface img, Sdl_o_rectangle pos);
};
