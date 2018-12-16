#include "./../header/wall.h"

Wall::Wall(int8_t ptype, int currentGameLevel, Sdl_o_surface bg, int xPosition, int yPosition)
{
  this->position = Sdl_o_rectangle(xPosition, yPosition, Wall::widthSpritePictureWithMargin, Wall::heightSpritePictureWithMargin);
  this->type = ptype;
  this->image = bg;
  scoreAndSprite();
  chooseWallType(type,currentGameLevel);
}

void Wall::chooseWallType(int8_t ptype, int currentGameLevel)
{
  if(ptype>=1 && ptype<=12) // normal wall
  {
    initNormalWall();
  }else if(ptype==13) // hard wall
  {
    initHardWall(currentGameLevel);
  }else if(ptype==14) // indestructible
  {
    initIndestructibleWall();
  }
}

void Wall::initNormalWall()
{
  this->indestructible = 0;
  this->health = 1;
  randomPower();
}

void Wall::initHardWall(int currentGameLevel)
{
  this->indestructible = 0;
  if(currentGameLevel<=8)
  {
    this->health = 2;
  }else if(currentGameLevel>=9 && currentGameLevel<=16)
  {
    this->health = 3;
  }else if(currentGameLevel>=17 && currentGameLevel<=24)
  {
    this->health = 4;
  }else if(currentGameLevel>=25 && currentGameLevel<=32)
  {
    this->health = 5;
  }
  this->points = 100*currentGameLevel;
  randomPower();
}

void Wall::initIndestructibleWall()
{
  this->indestructible = 1;
  this->health = 1;
  this->power = '0';
}

 void Wall::randomPower()
{
  this->power = rand()%2==1 ? 'C' : 'D';
  // int hasPower = rand()%5;
  // if(hasPower==0)
  // {
  //   char powers[7] = {'S', 'C', 'E', 'D', 'L', 'B', 'P'};
  //   this->power = powers[rand()%7];
  // }
  // else
  // {
  //   this->power = '0';
  // }
}

void Wall::scoreAndSprite()
{
  if(this->type==1)//50 points
  {
    this->positionImage = Sdl_o_rectangle(0,0,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 50;
  }else if(this->type==2)//50
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePictureWithMargin,0,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 50;
  }else if(this->type==3)//60
  {
    this->positionImage = Sdl_o_rectangle( (widthSpritePictureWithMargin)*2,0,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 60;
  }else if(this->type==4)//60
  {
    this->positionImage = Sdl_o_rectangle( (widthSpritePictureWithMargin)*3,0,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 60;
  }else if(this->type==5)//70
  {
    this->positionImage = Sdl_o_rectangle( (widthSpritePictureWithMargin)*4,0,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 70;
  }else if(this->type==6)//70
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePictureWithMargin*5,0,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 70;
  }else if(this->type==7)//80
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePictureWithMargin,heightSpritePictureWithMargin,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 80;
  }else if(this->type==8)//90
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePictureWithMargin*2,heightSpritePictureWithMargin,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 90;
  }else if(this->type==9)//100
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePictureWithMargin*3,heightSpritePictureWithMargin,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 100;
  }else if(this->type==10)//110
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePictureWithMargin*4,heightSpritePictureWithMargin,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 110;
  }else if(this->type==11)//120
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePictureWithMargin*5,heightSpritePictureWithMargin,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 120;
  }else if(this->type == 12)
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePictureWithMargin*3,(heightSpritePictureWithMargin)*2,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
    this->points = 120;
  }else if(this->type == 13)//hard wall
  {
    this->positionImage = Sdl_o_rectangle(0,(heightSpritePictureWithMargin)*2,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
  }else if(this->type == 14)//indestructible wall
  {
    this->positionImage = Sdl_o_rectangle(0,(heightSpritePictureWithMargin)*3,widthSpritePictureWithMargin,heightSpritePictureWithMargin);
  }

}
