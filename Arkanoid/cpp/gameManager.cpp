#include "./../header/gameManager.h"

GameManager::GameManager(int sizeWindowX, int sizeWindowY, char const *bg, int mode)
{
  topScoreAndLevelBorder = static_cast<int>((float)sizeWindowY*0.1);//top border for score and level
  m_window = Sdl_o_window("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeWindowX, sizeWindowY+topScoreAndLevelBorder, SDL_WINDOW_SHOWN);
  m_bg = Sdl_o_surface(bg);
  m_bg.setColor(true,0);
  m_window.getSurface().setColor(true, 0);
  m_mode = mode; //suppress warning

  //test (définir les dimensions des "games" automatiquement en fonction de la taille de la window pour plus tard)
  if(m_mode==SOLO) //solo
  {
      Game g1 = Game(0, sizeWindowX, topScoreAndLevelBorder, sizeWindowY+topScoreAndLevelBorder ,m_mode, m_bg, m_window);
      m_games.push_back(g1);
  }
  else if(m_mode==VERSUS)//duo versus
  {
    Game g1 = Game(0, sizeWindowX/2-(sizeWindowX*0.05), topScoreAndLevelBorder, sizeWindowY+topScoreAndLevelBorder ,m_mode, m_bg, m_window);
    Game g2 = Game(sizeWindowX/2+(sizeWindowX*0.05), sizeWindowX, topScoreAndLevelBorder, sizeWindowY+topScoreAndLevelBorder ,m_mode, m_bg, m_window);
    m_games.push_back(g1);
    m_games.push_back(g2);
  }


  startGame();
}


void GameManager::startGame()
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
        case SDL_KEYDOWN:
  				switch (event.key.keysym.sym)
  				{
            // touche clavier
  					case SDLK_LEFT:  m_games[PLAYER_1].updateVaultsPosition(-10); break;
  					case SDLK_RIGHT: m_games[PLAYER_1].updateVaultsPosition(+10); break;
  					default: break;
            if(m_mode>1)
            {
              case SDLK_w:  m_games[PLAYER_2].updateVaultsPosition(-10); break;
    					case SDLK_c: m_games[PLAYER_2].updateVaultsPosition(+10); break;
            }

  				}
  				break;
      }
    }
    refreshWindowAndObjects();
    SDL_Delay(10); // 50 fps
  }
}


void GameManager::refreshWindowAndObjects()
{
  for(Game& g : m_games)
  {
    Sdl_o_rectangle rectTexture = g.getTexturePosition();
    m_window.fillWindowWithSurface(m_bg, g.borders, rectTexture); // redraw the background
    g.updatePosition(); // update objects position for each game
  }
  m_window.updateScreen();


}
