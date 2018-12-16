#include "./../header/vault.h"

Vault::Vault(){};

Vault::Vault(Sdl_o_surface img, char p_size, int p_xStart, int p_yStart)
{
  this->fixedBall = nullptr;
  this->image = img;
  this->position = Sdl_o_rectangle(p_xStart,p_yStart,0,0); //we set the starting point, we will set the height and width in getTexturePosition based on texture sie
    getTexturePosition(p_size);
};


void Vault::getTexturePosition(char size)
{
  switch (size) {
    case 'm': //medium
      this->positionImage = Sdl_o_rectangle(384,127,65,17);
      this->position.m_width = 65;
      this->position.m_height = 17;
      break;
    case 'l': //large
      this->positionImage = Sdl_o_rectangle(384,191,98,17);
      this->position.m_width = 98;
      this->position.m_height = 17;
      break;
  }

}
