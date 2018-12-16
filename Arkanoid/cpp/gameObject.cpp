#include "./../header/gameObject.h"

GameObject::GameObject(){};
GameObject::GameObject(Sdl_o_surface img, Sdl_o_rectangle pos,  Sdl_o_rectangle startPos)
{
  GameObject::image = img;
  GameObject::positionImage = pos;
  GameObject::position = startPos;
}

bool GameObject::collision(GameObject o) //check collision between current gameobject and o
{
  if(position.m_x < o.position.m_x + o.position.m_width
    && position.m_x + position.m_width > o.position.m_width
    && position.m_y < o.position.m_y + o.position.m_height
    && position.m_height + position.m_y > o.position.m_y)
  {
    return true;
  }
  return false;
}
