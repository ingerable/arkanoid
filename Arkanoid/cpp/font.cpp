#include "./../header/font.h"

Font::Font()
{};

Font::Font(Sdl_o_surface p_path, Sdl_o_window* p_window)
{
  this->fontSurfaceBmp = p_path;
  this->window = p_window;
};

void Font::drawFont(char c, Sdl_o_rectangle position)
{
  int xPosition = ((c%16)-1)*widthFont;
  int yPosition = (static_cast<int>(ceil(c/16.0))-1)*heightFont;
  Sdl_o_rectangle fontSpritePos(xPosition, yPosition,widthFont,heightFont);
  this->window->drawGameObject(GameObject(this->fontSurfaceBmp, fontSpritePos, position), position);
};

void Font::drawFonts(std::vector<char> *codes, int xStart, int yStart)
{
  for(unsigned int i =0; i < codes->size(); i++)
  {
    drawFont(codes->at(i), Sdl_o_rectangle(xStart, yStart,widthFont, heightFont));
    xStart += widthFont/2;
  }
};

void Font::drawInt(int p_int,int xStart ,int yStart)
{
  std::string myString = std::to_string(p_int);
  std::vector<char> codesVector;
  for(unsigned int i = 0; i<myString.length(); i++)
  {
    char newCode = myString[i] -'0';
    newCode +=17; //17 is the first digit of the second line in the bmp file , so if we have code 0, we will look for 17+0 code
    codesVector.push_back(newCode);
  }
  drawFonts(&codesVector,xStart,yStart);

}
