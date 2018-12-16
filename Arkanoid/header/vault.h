#ifndef vault_H // #include guards
#define vault_H
#include "./../SDL2_OO/sdl_o_surface.h"
#include "./../header/gameObject.h"
#include "bonus.h"

class Vault: public GameObject
{

  public:
    Vault();
    Vault(Sdl_o_surface img, char p_size, int p_xStart, int p_yStart); //source image, wanted size(m: medium, l:large), starting x, starting y position
    using GameObject::GameObject; //parent constructor
    void getTexturePosition(char size);

    //bonus
    Ball *fixedBall; //ball curently fixed on vault (bonus catch and fire)
};

#endif
