#include "./../header/game.h"

Game::Game(int sizeX, int sizeY, int mode, char *bg)
{
  m_window = Sdl_o_window("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeX, sizeY, SDL_WINDOW_SHOWN);
  m_bg = Sdl_o_surface(bg);
  m_bg.setColor(true,0);

  //fill the window with the bg
  m_window.getSurface().setColor(true, 0);
  m_window.fillWindowWithSurface(m_bg);

  if(mode == SOLO)
  {
    initSolo();
  }
}

//init the different games object for SOLO mode
void Game::initSolo()
{
  m_balls.push_back(Ball(m_bg, Sdl_o_rectangle( 0,64,24,24 ), Sdl_o_rectangle(450,800,4,4)));
  m_vaults.push_back(Vault(m_bg , Sdl_o_rectangle(128,0,128,32),Sdl_o_rectangle((m_window.m_windowWidth/2)-30,m_window.m_windowHeight-30,30,30)));
  startGame();
}

void Game::startGame()
{
  SDL_Event event;
  bool quit = false;
  while (!quit)
  {
    while (!quit && SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          quit = true;
          break;
        default: break;
      }
    }
    refreshWindowAndObjects();
    SDL_Delay(10); // 50 fps
  }
}

void Game::refreshWindowAndObjects()
{
  //update balls (we will have to check collisions here)
  for(Ball& b : m_balls) {
    b.updatePosition(); //update rectangle attribute of ball
    m_window.drawGameObject((GameObject) b, b.position); //draw ball object on window
  }

  //update vaults
  for(Vault& v : m_vaults) {    
    m_window.drawGameObject((GameObject) v, v.position); //draw ball object on window
  }

  m_window.updateScreen();
  m_window.fillWindowWithSurface(m_bg); // redraw the background

  SDL_Delay(10); // 50 fps
}
