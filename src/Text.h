#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include <string>
#include <sstream>
#include <unordered_map>

#include "Camera.h"
#include "Game.h"
#include "Rect.h"

class Text
{
public:
	enum TextStyle {TEXT_SOLID,TEXT_SHADED,TEXT_BLENDED};
    Text(const std::string&,int,TextStyle,const std::string&,SDL_Color,int = 0,int = 0);
    ~Text();
    void render(int = 0,int = 0);
    void setPos(int,int,bool = false,bool= false);
    void setText(const std::string&);
    void setColor(SDL_Color);
    void setStyle(TextStyle);
    void setFontSize(int);
    static void clear();
   
private:
	void remakeTexture();
	TTF_Font* font;
	SDL_Texture* texture;
    std::string fontFile;
    std::string text;
	TextStyle style;
	int fontSize;
	SDL_Color color;
	Rect box;

	static std::unordered_map<std::string,TTF_Font*> assetTable;
};

#endif // TEXT_H
