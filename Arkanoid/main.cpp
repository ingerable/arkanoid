#ifndef main_H
#define main_H
#include "./header/gameManager.h"


int main()
{

  GameManager gm(13*Wall::widthSpritePicture,25*Wall::heightSpritePicture,"./bmp/sprites2.bmp", 1);

  return 0;
}

#endif
