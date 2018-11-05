#include "./../header/wall.h"

Wall::Wall(int8_t type, int currentGameLevel, Sdl_o_surface bg, int xPosition, int yPosition)
{
  this->position = Sdl_o_rectangle(xPosition, yPosition, Wall::widthSpritePicture, Wall::heightSpritePicture);
  this->type = type;
  this->image = bg;
  scoreAndSprite();
  chooseWallType(type,currentGameLevel);
}

void Wall::chooseWallType(int8_t type, int currentGameLevel)
{
  if(type>=1 && type<=12) // normal wall
  {
    initNormalWall();
  }else if(type>=13 && type<=18) // hard wall
  {
    initHardWall(currentGameLevel);
  }else if(type>=19 && type<= 22) // indestructible
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
  int hasPower = rand()%6;
  if(hasPower==0)
  {
    char powers[7] = {'S', 'C', 'E', 'D', 'L', 'B', 'P'};
    this->power = powers[rand()%7];
  }
  else
  {
    this->power = '0';
  }
}

void Wall::scoreAndSprite()
{
  if(this->type==1)//50 points
  {
    this->positionImage = Sdl_o_rectangle(0,0,widthSpritePicture,heightSpritePicture);
    this->points = 50;
  }else if(this->type==2)//50
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture+margin,0,widthSpritePicture,heightSpritePicture);
    this->points = 50;
  }else if(this->type==3)//60
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*2+margin,0,widthSpritePicture,heightSpritePicture);
    this->points = 60;
  }else if(this->type==4)//60
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*3+margin,0+margin,widthSpritePicture,heightSpritePicture);
    this->points = 60;
  }else if(this->type==5)//70
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*4+margin,0,widthSpritePicture,heightSpritePicture);
    this->points = 70;
  }else if(this->type==6)//70
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*5+margin,0,widthSpritePicture,heightSpritePicture);
    this->points = 70;
  }else if(this->type==7)//80
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture,heightSpritePicture+margin,widthSpritePicture,heightSpritePicture);
    this->points = 80;
  }else if(this->type==8)//90
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*2,heightSpritePicture+margin,widthSpritePicture,heightSpritePicture);
    this->points = 90;
  }else if(this->type==9)//100
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*3,heightSpritePicture+margin,widthSpritePicture,heightSpritePicture);
    this->points = 100;
  }else if(this->type==10)//110
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*4,heightSpritePicture+margin,widthSpritePicture,heightSpritePicture);
    this->points = 110;
  }else if(this->type==11)//120
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*5,heightSpritePicture+margin,widthSpritePicture,heightSpritePicture);
    this->points = 120;
  }else if(this->type == 12)
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*3,(heightSpritePicture+margin)*2,widthSpritePicture,heightSpritePicture);
    this->points = 120;
  }else if(this->type == 13)//hard wall
  {
    this->positionImage = Sdl_o_rectangle(0,(heightSpritePicture+margin)*2,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 14)
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture,(heightSpritePicture+margin)*2,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 15)
  {
    this->positionImage = Sdl_o_rectangle((widthSpritePicture+margin)*2,(heightSpritePicture+margin)*2,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 16)
  {
    this->positionImage = Sdl_o_rectangle( (widthSpritePicture+margin)*4,(heightSpritePicture+margin)*2,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 17)
  {
    this->positionImage = Sdl_o_rectangle( (widthSpritePicture+margin)*5,(heightSpritePicture+margin)*2,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 18)//indestructible wall
  {
    this->positionImage = Sdl_o_rectangle(0,(heightSpritePicture+margin)*3,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 19)
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture,(heightSpritePicture+margin)*3,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 20)
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*2,(heightSpritePicture+margin)*3,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 21)
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*4,(heightSpritePicture+margin)*3,widthSpritePicture,heightSpritePicture);
  }else if(this->type == 22)
  {
    this->positionImage = Sdl_o_rectangle(widthSpritePicture*5  ,(heightSpritePicture+margin)*3,widthSpritePicture,heightSpritePicture);
  }


}
