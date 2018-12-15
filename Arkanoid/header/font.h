#include "./../SDL2_OO/sdl_o_rectangle.h"
#include "./../SDL2_OO/sdl_o_window.h"
#include <math.h>
#include <string.h>
#include "gameObject.h"

class Font
{
  public:
    Sdl_o_surface fontSurfaceBmp;
    Sdl_o_rectangle target; //position were font should be drawn
    Sdl_o_window* window; //window where font should be draw
    const int widthFont = 17;
    const int heightFont = 27;

    Font(Sdl_o_surface path, Sdl_o_window* window);
    void drawFont(char c, Sdl_o_rectangle position); //draw font associated with code c at position position
    void drawFonts(std::string codes, int xStart, int yStart); //start at xStart and yStart, for each font code in codes, draw the font and increment to next position
};
