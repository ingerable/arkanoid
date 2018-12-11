#ifndef main_H
#define main_H
#include "./header/gameManager.h"
#include "./header/font.h"

int main(int argc, char *argv[])
{
  if(argc==2 && atoi(argv[1])<=2)GameManager gm(13*Wall::widthSpritePicture*atoi(argv[1]), 25*Wall::heightSpritePicture, "./bmp/sprites2.bmp", atoi(argv[1])); //otherwise we have warning because of unusued argc parameter
  return 0;
}

#endif
