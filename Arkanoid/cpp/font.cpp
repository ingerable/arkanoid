#include "./../header/font.h"

Font::Font(Sdl_o_surface p_path, Sdl_o_window* p_window)
{
  this->fontSurfaceBmp = p_path;
  this->window = p_window;
};

void Font::drawFont(char c, Sdl_o_rectangle position)
{
  int xPosition = (c*widthFont)%(16*widthFont);
  int yPosition = static_cast<int>(ceil(c/16.0));
  Sdl_o_rectangle fontSpritePos(xPosition, yPosition,widthFont,heightFont);

  this->window->drawGameObject(GameObject(this->fontSurfaceBmp, fontSpritePos, position), position);
};

void Font::drawFonts(std::string codes, int xStart, int yStart)
{
  for(std::string::size_type i =0; i <codes.size(); i++)
  {
    drawFont(codes[i], Sdl_o_rectangle(xStart, yStart,widthFont, heightFont));
    xStart += widthFont;
    //yStart += heightFont;
  }
};
