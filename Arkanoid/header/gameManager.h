#include "./../header/game.h"
#define PLAYER_1 0
#define PLAYER_2 1

class GameManager
{
  public:
    std::vector<Game> m_games;
    Sdl_o_window m_window;
    Sdl_o_surface m_bg; // image containing sprites
    int m_mode;

    GameManager(int sizeWindowX, int sizeWindowY,  char const *bg, int mode);
    void refreshWindowAndObjects();
    void startGame();
    void refreshWindow();
    int topScoreAndLevelBorder;
};
