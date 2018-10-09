#include "./../header/gameObject.h"

GameObject::GameObject(){};
GameObject::GameObject(Sdl_o_surface img, Sdl_o_rectangle pos,  Sdl_o_rectangle startPos)
{
  GameObject::image = img;
  GameObject::positionImage = pos;
  GameObject::position = startPos;
}
