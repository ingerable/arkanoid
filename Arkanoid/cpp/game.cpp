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
  borders = Sdl_o_rectangle(m_x1,m_y1, m_x2-m_x1, m_y2-m_y1); //x y width height

  if(mode == SOLO)
  {
    parseLevelText();
    initSolo();
  }
  else if(mode == VERSUS)
  {
    parseLevelText();
    initSolo();
  }
}

//init the different games object for SOLO mode
void Game::initSolo()
{
  int ball_vault_x = (m_x2+m_x1)/2; // x position for the vault and the ball (middle of window)

  m_balls.push_back(Ball(m_bg,'s',ball_vault_x,m_y2-90));
  m_vault = Vault(m_bg,'m',ball_vault_x ,m_y2-30);
  m_myFont = Font(Sdl_o_surface("./bmp/Arkanoid_ascii.bmp"),&m_window);

}

void Game::updatePosition()
{
  //update vault
  m_window.drawGameObject((GameObject) m_vault, m_vault.position); //draw ball object on window

  if(m_balls.empty() == false)
  {
    for(int i = m_balls.size() - 1; i >= 0; i--)
    {
      m_balls.at(i).updatePosition(); //update rectangle attribute of ball
      vaultCollision(m_balls.at(i));
      wallsCollision(m_balls.at(i));
      m_window.drawGameObject((GameObject) m_balls.at(i), m_balls.at(i).position); //draw ball object on window
      if(borderCollision(m_balls.at(i))) //ball felt out of level
      {
        m_balls.erase( m_balls.begin() + i ); //remove the ball
        //loose a life here
        this->health--;
      }
    }
  }
  //update walls
  for(Wall& w : m_walls) {
    m_window.drawGameObject((GameObject) w, w.position);
  }

  for(Bonus& bo : m_bonus ) {
    bo.updatePosition();
    m_window.drawGameObject((GameObject) bo, bo.position); //if bonus is currently falling then draw it
  }
  bonusCollision();

  //draw font
  m_myFont.drawInt(this->m_score,0,0); //draw score at given position
  m_myFont.drawInt(this->health,m_x2-(m_x2*0.1),0); //draw score at given position
}


void Game::run()
{
  if(this->health > 0)
  {
    updatePosition();
  }
  else
  {
    gameOver();
  }
}

void Game::bonusCollision()
{
  for (size_t j = 0; j < m_bonus.size(); j++)
  {
    if(m_bonus[j].position.m_y>=m_y2) //bonus felt outside level, delete it
    {
          m_bonus.erase(m_bonus.begin()+j);
    }
    else
    {
      if(m_vault.collision(m_bonus[j])) //if there there is collision between bonus and vault
      {
        triggerBonus(m_bonus[j]);
        m_bonus.erase(m_bonus.begin()+j);
      }
    }
  }
}

bool Game::borderCollision(Ball &ball)
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
    return true; //ball felt
  }
  return false;
}

void Game::vaultCollision(Ball &ball)
{
  if(ball.collision(m_vault))
  {
    if(isPowerActive('C') && m_vault.fixedBall == nullptr)
    { //if catch and fire is in bonus listœ
      catchAndFire(&ball);
    }
    else
    {
      //ball.bounceYWithAngle(m_vault.position.m_x,m_vault.position.m_x+m_vault.position.m_width);
      ball.bounceYWithAngle(m_vault.position.m_x,m_vault.position.m_x+m_vault.position.m_width);
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
                m_bonus.push_back(Bonus(i->power, m_bg, Sdl_o_rectangle(i->position.m_x, i->position.m_y, Bonus::widthLetterCaseSprite, Bonus::heightLetterCaseSprite)));
            }
            this->m_score += i->points;
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
  else if(m_current_level==33) //level 6
  {
    return Sdl_o_rectangle(320,128,48,63);
  }
  else //black screen
  {
    return Sdl_o_rectangle(190,65,50,50);
  }
}

//add x and y to vault position
void Game::updateVaultPosition(int x)
{
    if(isPowerActive('C') && this->m_vault.fixedBall != nullptr) //if catch and fire is active and ball is on vault, then move ball with the vault
    {
      this->m_vault.fixedBall->position.m_x += x;
    }
    int tmpPosXLeft = m_vault.position.m_x + x; //left of the vault
    int tmpPosXRight = m_vault.position.m_x + x + m_vault.position.m_width; //right of the vault
    if(tmpPosXLeft>=this->m_x1 && tmpPosXRight<=this->m_x2)
    m_vault.position.m_x = tmpPosXLeft;
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

void Game::triggerBonus(Bonus b)
{
  if(!isAlreadyActive(b)) //if same power is not active yet
  {
    switch (b.power)
    {
      case 'C': //catch and fire
        this->m_bonus_active.push_back(b);
        break;
      case 'S': //slow ball
        this->m_bonus_active.push_back(b);
        slowDownBall();
        break;
      case 'E': //expand vault
        this->m_bonus_active.push_back(b);
        m_vault.getTexturePosition('l');
        break;
        case 'P':
          this->health++;
          break;
      case 'D': //3 ball effect
        Ball b1 = Ball(m_bg,'s',m_balls.front().position.m_x,m_balls.front().position.m_y);
        b1.setSpeed(-2.0,-2.0);
        Ball b2 = Ball(m_bg,'s',m_balls.front().position.m_x,m_balls.front().position.m_y);
        b2.setSpeed(2.0,-2.0);
        m_balls.front().setSpeed(0.0,2.0);
        m_balls.push_back(b1);
        m_balls.push_back(b2);
        break;
    }
  }
}

bool Game::isAlreadyActive(Bonus bonus)
{
  for(Bonus b:this->m_bonus_active)
  {
    if(bonus.power == b.power)
    {
      return true;
    }
  }
  return false;
}

void Game::triggerActiveBonus()
{
  if(isPowerActive('C') && m_vault.fixedBall != nullptr)
  {
    m_vault.fixedBall->setSpeed(Ball::baseSpeedX, Ball::baseSpeedY);
    m_vault.fixedBall = nullptr; //reset the pointer of fixed ball
  }
}

void Game::slowDownBall()
{
  for(Ball &b : this->m_balls) {
      b.slowBall();
  }
}

void Game::catchAndFire(Ball *ball)
{
  if(m_vault.fixedBall == nullptr)
  {
    ball->position = Sdl_o_rectangle(m_vault.position.m_x+this->m_vault.position.m_width/2, this->m_vault.position.m_y, ball->position.m_width, ball->position.m_height);
    ball->setSpeed(0,0);
    m_vault.fixedBall = ball;
  }
}

bool Game::isPowerActive(char power)
{
  for(Bonus b : this->m_bonus_active) {
      if(b.power == power) {
        return true;
      }
  }
  return false;
}

void Game::removeBonusByPowerName(char name)
{
  if(m_bonus_active.empty() == false)
  {
    for(int i = m_bonus_active.size() - 1; i >= 0; i--)
    {
      if(m_bonus_active.at(i).power == name)
      {
        m_bonus_active.erase( m_bonus_active.begin() + i );
      }
    }
  }
}

void Game::gameOver()
{
  m_current_level = -1; //so we have dark background
  std::vector<char> gameOver {40,34,46,38,1,17,55,38,51};
  m_myFont.drawFonts(&gameOver,static_cast<int>(m_x2/2-(0.25*m_x2)), m_y2/2);
}
