#include "./../SDL2_OO/sdl_o_rectangle.h"
#include "./../SDL2_OO/sdl_o_window.h"
#include <math.h>
#include <string.h>
class Font
{
  public:
    char* pathBmp;
    Sdl_o_window* window; //window where font should be draw
    const int widthFont = 17;
    const int heightFont = 27;

    Font(char* path, Sdl_o_window* window);
    //Sdl_o_rectangle drawFont(char c, Sdl_o_rectangle position); //draw font associated with code c at position position
    void drawFonts(std::string codes, int& xStart, int& yStart); //start at xStart and yStart, for each font code in codes, draw the font and increment to next position
};
