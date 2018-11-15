#pragma once
#include "./../header/gameObject.h"

class Bonus: public GameObject
{
  public:
    //const for sprite position
    static const int widthLetterCaseSprite = 32;
    static const int heightLetterCaseSprite = 15;
    static const int xBeggining = 256; // x of the first case of the letter sprite
    static const int xEnd = 316; //end of the sprite

    static const int fallingSpeed = 2;
    char power;
    bool isActive = 0;
    bool isFalling = 1;

    Bonus(char power, Sdl_o_surface img, Sdl_o_rectangle startPos);
    Bonus(char power, Sdl_o_surface img, Sdl_o_rectangle startPos, bool isActive, bool isFalling);

    void updatePositionAndSprite();
    void getTexturePosition();
};
