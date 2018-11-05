#include "./../header/game.h"
#define PLAYER_1 0
#define PLAYER_2 1
#define block_w 31
#define block_h 15

class GameManager
{
  public:
    std::vector<Game> m_games;
    Sdl_o_window m_window;
    Sdl_o_surface m_bg; // image containing sprites

    GameManager(int sizeWindowX, int sizeWindowY,  char* bg, int mode);
    void refreshWindowAndObjects();
    void startGame();
    void refreshWindow();
};
