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
  borders = Sdl_o_rectangle(m_x1,m_y1, m_x2-m_x1, m_y2-m_y1);
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

  m_balls.push_back(Ball(m_bg, Sdl_o_rectangle(ball_vault_x,m_y2-90,60,60)));
  m_vaults.push_back(Vault(m_bg,Sdl_o_rectangle(ball_vault_x,m_y2-30,60,60)));
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
    m_window.drawGameObject((GameObject) w, w.position);
  }

  for(Bonus& bo : m_bonus ) {
    bo.updatePosition();
    m_window.drawGameObject((GameObject) bo, bo.position);
  }
  bonusCollision();
}

void Game::bonusCollision()
{
  //auto i = std::begin(m_bonus);
  //auto last = m_bonus.empty() ? m_bonus.end() : std::prev(m_bonus.end());
  for (size_t j = 0; j < m_bonus.size(); j++) {
    if(m_bonus[j].position.m_y>=m_y2) //bonus felt outside level, delete it
    {
          m_bonus.erase(m_bonus.begin()+j);
    }
  }
}

void Game::borderCollision(Ball &ball)
{
  if(ball.getX()<=m_x1)
  {
    ball.bounceX();
  }
  else if(ball.getX()>=m_x2)
  {
    ball.bounceX();
  }

  if(ball.getY()<=m_y1)
  {
    ball.bounceY();

  }
  else if(ball.getY()>=m_y2)
  {
    ball.fall();
    //loose a life here
  }
}

void Game::vaultCollision(Ball &ball)
{
  for(Vault& v : m_vaults) {
    if(ball.getX()<= (v.position.m_x+v.position.m_width) && ball.getX() >= (v.position.m_x))
    {
      if(ball.getY() >= v.position.m_y)
      {
        ball.bounceY();
      }
    }
  }
}

void Game::wallsCollision(Ball &ball)
{
  auto i = std::begin(m_walls);
  while(i != std::end(m_walls))
  {
      if(ball.getY() <= (i->position.m_y+i->position.m_height) && ball.getY() >= i->position.m_y)
      {
        if(ball.getX()<= (i->position.m_x+i->position.m_width) && ball.getX() >= (i->position.m_x))
        {
          ball.bounceY();
          i->health--;
          if(i->indestructible==0 && i->health==0)
          {
            if(i->power != '0') {
                m_bonus.push_back(Bonus(i->power, m_bg, Sdl_o_rectangle(i->position.m_x, i->position.m_y, Bonus::widthLetterCaseSprite, Bonus::heightLetterCaseSprite), false, true));
            }
            this->score += i->points;
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
        ++i;
      }
  }


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
  else //if(m_current_level==33) //level 6
  {
    return Sdl_o_rectangle(320,128,48,63);
  }
}

//add x and y to vault position
void Game::updateVaultsPosition(int x)
{
  for(Vault& v : m_vaults)
  {
    int tmpPosXLeft = v.position.m_x + x; //left of the vault
    int tmpPosXRight = v.position.m_x + x + v.position.m_width; //right of the vault
    if(tmpPosXLeft>=this->m_x1 && tmpPosXRight<=this->m_x2)
    v.position.m_x = tmpPosXLeft;
  }
}

void Game::parseLevelText()
{
  char buffer[256];
  char *val = getcwd(buffer, sizeof(buffer));
  std::string path = std::string(val);

  char x;
  std::ifstream fileLevel;
  std::string txtPath = path + "/levels/" + std::to_string(m_current_level) + ".txt";
  std::cout<<txtPath<<"\n";
  fileLevel.open(txtPath);
  if(!fileLevel) {
    std::cout<<"problem while opening level file"<<"\n";
    std::cout<<"path: "<<txtPath;
    exit(1);
  }

  int xCursor = this->m_x1;
  int yCursor = this->m_y1;
  char code[2]; // can be one or 2 char code
  int i=0;
  int ix; //code with int representation instead of array

  while (fileLevel >> x) {
    i = 0;
    code[1] = 'n'; // for the moment there is noting at the index 1 of the code
    while(x!=';' && i!=2) //iterate until separator, and a code cannot be longer than 2 char
    {
      code[i] = x;
      fileLevel >> x;
      i++;
    }
    if(code[0] == '0') //blank space
    {
      xCursor += Wall::widthSpritePicture;

    }else if(code[0] == 'n')//jump a line
    {
      yCursor += Wall::heightSpritePicture;
    }
    else // place a wall
    {
      if(code[1]=='n') // 1 char code
      {
        ix = code[0] - '0'; //conversion from char to int representation
        placeWall(ix, xCursor, yCursor);
      }
      else // 2 char code
      {
        sscanf(code,"%d",&ix); // 2 char array into 1 int
        placeWall(ix,xCursor, yCursor);
      }
    }
  }
  fileLevel.close();
}

void Game::placeWall(int code, int &xCursor, int &yCursor) // instantiate and place a wall with code at position (xCursor,yCursor)
{
  Wall wall;
  if( (xCursor+Wall::widthSpritePicture)>this->m_x2) //xCursor exceed border
  {
    xCursor = 0;
    yCursor += Wall::heightSpritePicture;
    m_walls.push_back(Wall(code, this->m_current_level, this->m_bg,xCursor,yCursor));
    xCursor += Wall::widthSpritePicture;
  }
  else
  {
      m_walls.push_back(Wall(code, this->m_current_level, this->m_bg,xCursor,yCursor));
      xCursor += Wall::widthSpritePicture;
  }
}
