#pragma once
#include "./../SDL2_OO/sdl_o_rectangle.h"
#include "./../SDL2_OO/sdl_o_surface.h"

class GameObject
{
  public:
    Sdl_o_surface image;
    Sdl_o_rectangle positionImage;
    Sdl_o_rectangle position;

  public:
    GameObject();
    GameObject(Sdl_o_surface img, Sdl_o_rectangle pos, Sdl_o_rectangle startPos);
    bool collision(GameObject o); //check collision between current gameobject and o
};
