#include "./../header/vault.h"

Vault::Vault(){};

Vault::Vault(Sdl_o_surface img, Sdl_o_rectangle startPos)
{
  this->image = img;
  this->position = startPos;
  getTexturePosition();
};


void Vault::getTexturePosition()
{
  this->positionImage = Sdl_o_rectangle(384,127,65,17);
}
