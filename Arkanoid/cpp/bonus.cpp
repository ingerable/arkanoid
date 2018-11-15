#include "./../header/bonus.h"


Bonus::Bonus(char power, Sdl_o_surface img, Sdl_o_rectangle startPos)
{
  this->power = power;
  this->image = img;
  this->position = startPos;
};

Bonus::Bonus(char power, Sdl_o_surface img, Sdl_o_rectangle startPos, bool isActive, bool isFalling)
{
  this->power = power;
  this->image = img;
  this->position = startPos;
  this->isActive = isActive;
  this->isFalling = isFalling;
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

void Bonus::updatePositionAndSprite()
{
this->position.m_y += fallingSpeed;
 this->positionImage.setX( (this->positionImage.m_x+widthLetterCaseSprite+xBeggining)%xEnd);
}
