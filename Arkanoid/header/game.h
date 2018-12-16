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
    Vault m_vault;
    std::vector<Wall> m_walls; // lists of walls
    std::vector<Bonus> m_bonus; //list of falling bonus(non-active)
    std::vector<Bonus> m_bonus_active; //list of active bonus
    std::vector<GameObject> m_projectiles;

    Font m_myFont; //font object that draw on window
    Sdl_o_surface m_bg; // image containing sprites
    Sdl_o_window m_window; //window containing one or more games (for the moment 1 or 2)
    int m_score = 0;
    int m_current_level = 1;
    int m_x1; // borders of the game
    int m_x2;
    int m_y1;
    int m_y2;
    int health = 3;
    Sdl_o_rectangle borders;

    void initSolo();
    void initCoop();
    void refreshWindowAndObjects();
    void startGame();
    Sdl_o_rectangle getTexturePosition(); //get texture position depending on current level
    void parseLevelText();
    Game(int x1, int x2 , int y1, int y2, int mode, Sdl_o_surface s, Sdl_o_window w);


    //collision
    void updatePosition();
    void run();
    void wallsCollision(Ball &ball);
    bool borderCollision(Ball &ball);
    void vaultCollision(Ball &ball);
    void updateVaultPosition(int x);
    void bonusCollision(); //check if bonus hit a vault => give bonus to player or if bonus felt outside level =>delete falling bonus

    //wall section
    void chooseWallType(char type);
    void placeWall(int code, int &xCursor, int &yCursor);

    //bonus
    void removeBonusByPowerName(char name); //remove bonus with power name ('C', 'S')
    void triggerActiveBonus(); //trigger an active bonus (with a key for example)
    void triggerBonus(Bonus b); //trigger a bonus
    bool isAlreadyActive(Bonus b); //check if given bonus is already active
    bool isPowerActive(char power); //check if bonus with power power is active

    //bonus effect
    void slowDownBall();
    void catchAndFire(Ball *ball);

    //next level and game over
    void gameOver();
};
