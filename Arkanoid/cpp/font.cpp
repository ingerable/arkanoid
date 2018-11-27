#include "./../header/font.h"

Font::Font(char* path, Sdl_o_window* window)
{
  this->pathBmp = path;
  this->window = window;
};

Sdl_o_rectangle Font::drawFont(char c, Sdl_o_rectangle position)
{
/*  int xPosition = (c*widthFont)%(16*widthFont);
  int yPosition = static_cast<int>(ceil(c/16.0));
  std::cout<<yPosition<<"\n";
  this->window->fillWindowWithSurface(this->pathBmp, g.borders, Sdl_o_rectangle( , )); // redraw the background*/
};


void Font::drawFonts(std::string codes, int& xStart, int& yStart)
{
  for(std::string::size_type i =0; i <codes.size(); i++)
  {
    drawFont(codes[i], Sdl_o_rectangle(xStart, yStart,widthFont, heightFont));
    xStart += widthFont;
    yStart += heightFont;
  }
}
