#pragma once
#include "./../header/gameObject.h"
#include "ball.h"

class Bonus: public GameObject
{
  public:
    //const for sprite position
    static const int widthLetterCaseSprite = 32;
    static const int heightLetterCaseSprite = 15;
    static const int xBeggining = 256; // x of the first case of the letter sprite
    static const int xEnd = 512; //end of the sprite

    static const int fallingSpeed = 1;
    char power;

    Bonus(char power, Sdl_o_surface img, Sdl_o_rectangle startPos);

    void updatePosition();
    void getTexturePosition();

};
