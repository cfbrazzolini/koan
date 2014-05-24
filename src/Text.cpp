#include "Text.h"

std::unordered_map<std::string,TTF_Font*> Text::assetTable;

Text::Text(const std::string& fontFile,int fontSize,TextStyle style,const std::string& text,SDL_Color color,int x,int y) :	fontFile(fontFile),
																															fontSize(fontSize),
																															style(style),
																															text(text),
																															color(color)
{
	std::string result;
	std::stringstream sstream;


	box.setX(x);
	box.setY(y);
	box.setW(0);
	box.setH(0);

	texture = nullptr;

    if((font = TTF_OpenFont(fontFile.c_str(),fontSize)) != nullptr){
		sstream << fontFile << fontSize;
        result = sstream.str();
		
		assetTable.emplace(result,font);
		remakeTexture();
	}
}

Text::~Text(){
	if(texture != nullptr){
		SDL_DestroyTexture(texture);
	}
}

void Text::render(int cameraX,int cameraY){

	SDL_Rect src_rect,dst_rect;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = box.getW();
	src_rect.h = box.getH();

	dst_rect.x = cameraX + box.getX();
	dst_rect.y = cameraY + box.getY();
	dst_rect.w = box.getW();
	dst_rect.h = box.getH();

	if(texture != nullptr){
		SDL_RenderCopy(Game::getInstance().getRenderer(),texture,&src_rect,&dst_rect);
	}
}

void Text::setPos(int x,int y,bool centerX,bool centerY){
	if(centerX == true){
		x -= box.getW()/2;
	}

	if(centerY == true){
        y -= box.getH()/2;
	}

	box.setX(x);
	box.setY(y);
}

void Text::setText(const std::string& text){
	this->text = text;
	remakeTexture();
}

void Text::setColor(SDL_Color color){
	this->color = color;
	remakeTexture();
}

void Text::setStyle(TextStyle style){
	this->style = style;
	remakeTexture();
}

void Text::setFontSize(int fontSize){
	this->fontSize = fontSize;
	remakeTexture();
}

void Text::clear(){
	for ( auto it = assetTable.begin(); it!= assetTable.end(); ++it ){
       TTF_CloseFont(it->second);
    }
    assetTable.clear();
}

void Text::remakeTexture(){

	SDL_Surface* surface;
	SDL_Rect dimensions;

	if(texture != nullptr){
		SDL_DestroyTexture(texture);
	}

	switch(style){

		case TEXT_SOLID:
            surface = TTF_RenderText_Solid(font,text.c_str(),color);
			break;
		case TEXT_SHADED:
            SDL_Color bg;
            surface = TTF_RenderText_Shaded(font,text.c_str(),color,bg);
			break;
		case TEXT_BLENDED:
            surface = TTF_RenderText_Blended(font,text.c_str(),color);
			break;
	}

	texture = SDL_CreateTextureFromSurface(Game::getInstance().getRenderer(),surface);
	SDL_FreeSurface(surface);

	SDL_QueryTexture(texture,0,0,&dimensions.w,&dimensions.h);
	box.setW(dimensions.w);
	box.setH(dimensions.h);


}
