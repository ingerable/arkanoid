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
    std::vector<Vault> m_vaults; //list of vaults , in case we are in cooperative mode
    Sdl_o_surface m_bg; // image containing sprites
    Sdl_o_window m_window; //window containing one or more games (for the moment 1 or 2)
    int score = 0;
    int m_current_level = 33;
    int m_x1; // borders of the game
    int m_x2;
    int m_y1;
    int m_y2;

    void initSolo();
    void initCoop();
    void refreshWindowAndObjects();
    void startGame();
    Game(int x1, int x2 , int y1, int y2, int mode, Sdl_o_surface s, Sdl_o_window w);
    void updatePosition();
    void ballCollision(Ball &ball);
    Sdl_o_rectangle getTexturePosition(); //get texture position depending on current level
    Sdl_o_rectangle getBorders();
};
