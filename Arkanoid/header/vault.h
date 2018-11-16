#ifndef vault_H // #include guards
#define vault_H
#include "./../SDL2_OO/sdl_o_surface.h"
#include "./../header/gameObject.h"

class Vault: public GameObject
{

  public:
    Vault();
    Vault(Sdl_o_surface img, Sdl_o_rectangle startPos);
    using GameObject::GameObject; //parent constructor
    void getTexturePosition();
};

#endif
