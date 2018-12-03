#include "./../header/bonus.h"


Bonus::Bonus(char p_power, Sdl_o_surface p_img, Sdl_o_rectangle p_startPos)
{
  this->power = p_power;
  this->image = p_img;
  this->position = p_startPos;
};

Bonus::Bonus(char p_power, Sdl_o_surface p_img, Sdl_o_rectangle p_startPos, bool p_isActive, bool p_isFalling)
{
  this->power = p_power;
  this->image = p_img;
  this->position = p_startPos;
  this->isActive = p_isActive;
  this->isFalling = p_isFalling;
  getTexturePosition();
};

void Bonus::getTexturePosition()
{
  switch (this->power) {
    case 'S':
      this->positionImage = Sdl_o_rectangle(xBeggining,0,widthLetterCaseSprite,heightLetterCaseSprite);
      break;
    case 'C':
      this->positionImage = Sdl_o_rectangle(xBeggining,heightLetterCaseSprite,widthLetterCaseSprite,heightLetterCaseSprite);
      break;
    case 'L':
      this->positionImage = Sdl_o_rectangle(xBeggining,heightLetterCaseSprite*2,widthLetterCaseSprite,heightLetterCaseSprite);
      break;
    case 'E':
      this->positionImage = Sdl_o_rectangle(xBeggining,heightLetterCaseSprite*3+2,widthLetterCaseSprite,heightLetterCaseSprite);
      break;
    case 'D':
      this->positionImage = Sdl_o_rectangle(xBeggining,heightLetterCaseSprite*4+2,widthLetterCaseSprite,heightLetterCaseSprite);
      break;
    case 'B':
      this->positionImage = Sdl_o_rectangle(xBeggining,heightLetterCaseSprite*5+4,widthLetterCaseSprite,heightLetterCaseSprite);
      break;
    case 'P':
      this->positionImage = Sdl_o_rectangle(xBeggining,heightLetterCaseSprite*6+5,widthLetterCaseSprite,heightLetterCaseSprite);
      break;
  }
}

void Bonus::updatePosition()
{
  this->position.m_y += fallingSpeed;
  if(this->positionImage.m_x >= xEnd) {
    this->positionImage.setX(xBeggining);
  } else {
      this->positionImage.setX( (this->positionImage.m_x+widthLetterCaseSprite));
  }
}
