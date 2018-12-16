#include "./../SDL2_OO/sdl_o_rectangle.h"
#include "./../SDL2_OO/sdl_o_window.h"
#include <math.h>
#include <string.h>
#include "gameObject.h"
#include <vector>

class Font
{
  public:
    Sdl_o_surface fontSurfaceBmp;
    Sdl_o_rectangle target; //position were font should be drawn
    Sdl_o_window* window; //window where font should be draw
    static const int widthFont = 32;
    static const int heightFont = 32;

    Font(Sdl_o_surface path, Sdl_o_window* window);
    Font();
    void drawFont(char c, Sdl_o_rectangle position); //draw font associated with code c at position position
    void drawFonts(std::vector<char> *codes, int xStart, int yStart); //start at xStart and yStart, for each font code in codes, draw the font and increment to next position
    void drawInt(int p_int,int xStart ,int yStart); //draw given int by slicing it and calling drawFonts
};
