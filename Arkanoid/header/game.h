#include "ball.h"
#include "vault.h"
#include <vector>
#include "./../SDL2_OO/sdl_o_window.h"
#include "./../SDL2_OO/sdl_o_surface.h"
#define SOLO 1
#define COOP 2


class Game // this class handle gamemode for only ONE window but one or more player
{
  public:
    std::vector<Ball> m_balls; //list of ball in the current game, in case ball split in 3 energy ball
    Sdl_o_window m_window;
    std::vector<Ball> m_vaults; //list of vaults , in case we are in cooperative mode
    Sdl_o_surface m_bg; // image containing sprites
    int score = 0;

    void initSolo();
    void initCoop();
    void refreshWindowAndObjects();
    void startGame();
    Game(int sizeX, int sizeY, int mode, char *bg);
};
