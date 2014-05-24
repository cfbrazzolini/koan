#include "MultiTileSet.h"


MultiTileSet::MultiTileSet(int tileWidth, int tileHeight)
{

    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
}

MultiTileSet::~MultiTileSet(){
    tileArray.clear();
}

void MultiTileSet::open(const std::string& file){
    tileArray.emplace_back(file);
}

void MultiTileSet::render(unsigned index,int x,int y){


    if(index >= tileArray.size()){
    	
    }else{
        tileArray[index].render(x,y);
    }
}
