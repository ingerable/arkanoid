#include "./../header/game.h"
#include <unistd.h>

Game::Game(int x1, int x2 , int y1, int y2, int mode, Sdl_o_surface s, Sdl_o_window w)
{
  m_x1 = x1;
  m_x2 = x2;
  m_y1 = y1;
  m_y2 = y2;
  m_bg = s;
  m_window = w;
  if(mode == SOLO)
  {
    parseLevelText();
    initSolo();
  }
}

//init the different games object for SOLO mode
void Game::initSolo()
{
  int ball_vault_x = (m_x2+m_x1)/2; // x position for the vault and the ball (middle of window)

  m_balls.push_back(Ball(m_bg, Sdl_o_rectangle( 4,66,8,8 ), Sdl_o_rectangle(ball_vault_x,m_y2-90,60,60)));
  m_vaults.push_back(Vault(m_bg , Sdl_o_rectangle(384,127,65,17),Sdl_o_rectangle(ball_vault_x,m_y2-30,60,60)));
}

void Game::updatePosition()
{
  //update vaults
  for(Vault& v : m_vaults) {
    m_window.drawGameObject((GameObject) v, v.position); //draw ball object on window
  }

  //update balls (we will have to check collisions here)
  for(Ball& b : m_balls) {
    b.updatePosition(); //update rectangle attribute of ball
    borderCollision(b);
    vaultCollision(b);
    wallsCollision(b);
    m_window.drawGameObject((GameObject) b, b.position); //draw ball object on window
  }

  //update walls
  for(Wall& w : m_walls) {
    m_window.drawGameObject((GameObject) w, w.position); //draw ball object on window
  }

}

void Game::borderCollision(Ball &ball)
{
  if(ball.getX()<=m_x1)
  {
    ball.speedX = -ball.speedX;
  }
  else if(ball.getX()>=m_x2)
  {
    ball.speedX = -ball.speedX;
  }

  if(ball.getY()<=m_y1)
  {
    ball.speedY = -ball.speedY;

  }
  else if(ball.getY()>=m_y2)
  {
    ball.speedY = 0;
    std::cout<<"perdu";//loose a life
  }
}

void Game::vaultCollision(Ball &ball)
{
  for(Vault& v : m_vaults) {
    if(ball.getX()<= (v.position.m_x+v.position.m_width) && ball.getX() >= (v.position.m_x))
    {
      if(ball.getY() >= v.position.m_y)
      {
        ball.speedY = -ball.speedY;
      }
    }
  }
}

void Game::wallsCollision(Ball &ball)
{
  auto i = std::begin(m_walls);
  while(i != std::end(m_walls))
  {
      if( ball.getY() <= (i->position.m_y+i->position.m_height) && ball.getY() >= i->position.m_y)
      {
        if(ball.getX()<= (i->position.m_x+i->position.m_width) && ball.getX() >= (i->position.m_x))
        {
          ball.speedY = -ball.speedY;
          i->health--;
          if(i->health==0)
          {
            m_walls.erase(i);
          }
          else
          {
            ++i;
          }
        }
        else
        {
          ++i;
        }
      }
      else
      {
        //std::cout<<"ball Y :"<<ball.getY()<<"\n";
        //std::cout<<"wall Y :"<< i->position.m_y+i->position.m_height<<"\n";
        ++i;
      }
  }


}

void hasCollision(Ball &ball, Wall wall)
{

}

Sdl_o_rectangle Game::getTexturePosition()
{
  if(m_current_level>0 && m_current_level<7) //level 1
  {
    return Sdl_o_rectangle(0,128,48,63);
  }
  else if(m_current_level>7 && m_current_level<14) //level 2
  {
    return Sdl_o_rectangle(64,128,48,63);
  }
  else if(m_current_level>14 && m_current_level<21) //level 3
  {
    return Sdl_o_rectangle(128,128,48,63);
  }
  else if(m_current_level>21 && m_current_level<28) //level 4
  {
    return Sdl_o_rectangle(192,128,48,63);
  }
  else if(m_current_level>28 && m_current_level<32) //level 5
  {
    return Sdl_o_rectangle(256,128,48,63);
  }
  else if(m_current_level==33) //level 6
  {
    return Sdl_o_rectangle(320,128,48,63);
  }
}

Sdl_o_rectangle Game::getBorders()
{
  return Sdl_o_rectangle(m_x1,m_y1, m_x2-m_x1, m_y2-m_y1);
}

//add x and y to vault position
void Game::updateVaultsPosition(int x, int y)
{
  for(Vault& v : m_vaults)
  {
    v.position.m_x += x;
    v.position.m_y += y;
  }
}


void Game::parseLevelText()
{

  char buffer[256];
  char *val = getcwd(buffer, sizeof(buffer));
  std::string path = std::string(buffer);

  char x;
  std::ifstream fileLevel;
  std::string txtPath = path + "/levels/" + std::to_string(m_current_level) + ".txt";
  fileLevel.open(txtPath);
  if(!fileLevel) {
    std::cout<<"problem while opening level file"<<"\n";
    std::cout<<"path: "<<txtPath;
    exit(1);
  }

  int xCursor = 0;
  int yCursor = 0;

  while (fileLevel >> x) {

    if(x == '0') //blank space
    {
      xCursor += Wall::widthSpritePicture;

    }else if(x == 'n')//jump a line
    {
      yCursor += Wall::heightSpritePicture;
    }
    else // place a wall
    {
      int8_t ix = x - '0'; //conversion from char to int representation
      Wall wall(ix, this->m_current_level, this->m_bg,xCursor,yCursor);
      //update cursor
      if( (xCursor+Wall::widthSpritePicture)>=this->m_x2) //xCursor exceed border
      {
        yCursor += Wall::heightSpritePicture;
        xCursor = 0;
      }else{
        xCursor += Wall::widthSpritePicture;
      }
      m_walls.push_back(wall);
    }
  }
  fileLevel.close();
}
