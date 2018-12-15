#include "ball.h"
#include "vault.h"
#include "wall.h"
#include "bonus.h"
#include "font.h"
#include <vector>
#include "./../SDL2_OO/sdl_o_window.h"
#include "./../SDL2_OO/sdl_o_surface.h"
#include <fstream>
#include <iostream>
#include <string>
#define SOLO 1
#define VERSUS 2

class Game // this class handle gamemode for only ONE window but one or more player
{
  public:
    std::vector<Ball> m_balls; //list of ball in the current game, in case ball split in 3 energy ball
    std::vector<Vault> m_vaults; //list of vaults , in case we are in cooperative mode
    std::vector<Wall> m_walls; // lists of walls
    std::vector<Bonus> m_bonus; //list of falling bonus(non-active)
    std::vector<Bonus> m_bonus_active; //list of active bonus

    Sdl_o_surface m_bg; // image containing sprites
    Sdl_o_window m_window; //window containing one or more games (for the moment 1 or 2)
    int score = 0;
    int m_current_level = 1;
    int m_x1; // borders of the game
    int m_x2;
    int m_y1;
    int m_y2;
    Sdl_o_rectangle borders;

    void initSolo();
    void initCoop();
    void refreshWindowAndObjects();
    void startGame();
    Game(int x1, int x2 , int y1, int y2, int mode, Sdl_o_surface s, Sdl_o_window w);
    void updatePosition();
    void wallsCollision(Ball &ball);
    void borderCollision(Ball &ball);
    void vaultCollision(Ball &ball);
    Sdl_o_rectangle getTexturePosition(); //get texture position depending on current level
    void parseLevelText();
    void updateVaultsPosition(int x);
    void bonusCollision(); //check if bonus hit a vault => give bonus to player or if bonus felt outside level =>delete falling bonus

    //wall section
    void chooseWallType(char type);
    void placeWall(int code, int &xCursor, int &yCursor);

    //bonus
    void triggerBonus(Bonus b);
    bool isAlreadyActive(Bonus b);
    //bonus effect
    void slowDownBall();
    void catchAndFire();
};
