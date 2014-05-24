#include "BlockTileSet.h"

BlockTileSet::BlockTileSet(int _tileWidth,int _tileHeight,const std::string& file){
	
	tileWidth = _tileWidth;
	tileHeight = _tileHeight;
	open(file);
}

void BlockTileSet::open(const std::string& file){

	tileSet.open(file);

	rows = tileSet.getHeight() / tileHeight;
    columns = tileSet.getWidth() / tileWidth;
}


void BlockTileSet::render(unsigned index,float x,float y){

	if(index < rows*columns){
    
        int tileX = tileWidth  * (index % columns);
        int tileY = tileHeight * (index / columns);


        tileSet.setClip(tileX, tileY, tileWidth, tileHeight);
        tileSet.render(x, y);
    }
}
