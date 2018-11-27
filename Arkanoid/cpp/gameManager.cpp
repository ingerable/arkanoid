#include "./../header/gameManager.h"

GameManager::GameManager(int sizeWindowX, int sizeWindowY, char *bg, int mode)
{
  topScoreAndLevelBorder = static_cast<int>((float)sizeWindowY*0.1);//top border for score and level
  m_window = Sdl_o_window("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sizeWindowX, sizeWindowY+topScoreAndLevelBorder, SDL_WINDOW_SHOWN);
  m_bg = Sdl_o_surface(bg);
  m_bg.setColor(true,0);
  m_window.getSurface().setColor(true, 0);

  //test (définir les dimensions des "games" automatiquement en fonction de la taille de la window pour plus tard)
  Game g1 = Game(0, sizeWindowX, topScoreAndLevelBorder, sizeWindowY+topScoreAndLevelBorder ,1, m_bg, m_window);
  m_games.push_back(g1);

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
