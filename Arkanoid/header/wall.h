#ifndef wall_h // #include guards
#define wall_h
#include "./../header/gameObject.h"
#include <time.h>

class Wall: public GameObject
{
  public:
    bool indestructible;
    int health;
    char power;
    int8_t points;
    int8_t type;
    Sdl_o_surface m_bg;

    //constants static
    static const int widthSpritePicture = 30;
    static const int heightSpritePicture = 13;
    static const int margin = 2;
    static const int widthSpritePictureWithMargin = widthSpritePicture+margin;
    static const int heightSpritePictureWithMargin = heightSpritePicture+margin;

    Wall(int8_t type, int currentGameLevel, Sdl_o_surface bg, int xPosition, int yPosition);
    void chooseWallType(int8_t type, int currentGameLevel);
    using GameObject::GameObject; //parent constructor

    //initialization of different kind of wall
    void initHardWall(int currentGameLevel);
    void initIndestructibleWall();
    void initNormalWall();

    void randomPower();
    void scoreAndSprite();
};

#endif
