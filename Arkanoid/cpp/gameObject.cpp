#include "./../header/gameObject.h"

GameObject::GameObject(){};
GameObject::GameObject(Sdl_o_surface img, Sdl_o_rectangle pos)
{
  GameObject::image = img;
  GameObject::positionImage = pos;
}
