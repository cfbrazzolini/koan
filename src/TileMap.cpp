#include "TileMap.h"
#include <iostream>

TileMap::TileMap(int mapWidth,int mapHeight,int mapDepth,TileSet* tileSet){

    int i;

    this->mapWidth = mapWidth;
    this->mapHeight = mapHeight;
    this->mapDepth = mapDepth;
    this->tileSet = tileSet;

    tileMatrix.assign(mapWidth*mapHeight*mapDepth, -1);
}

TileMap::TileMap(const std::string& file,TileSet* tileSet){

    this->tileSet = tileSet;
    load(file);
}

void TileMap::load(const std::string& file_name){

    std::ifstream file (file_name);
    std::string str;
    int i,j,k;

    
    if(file.is_open()){

        getline(file,str,',');
        this->mapWidth = strtol(str.c_str(),nullptr,10);
        getline(file,str,',');
        this->mapHeight = strtol(str.c_str(),nullptr,10);
        getline(file,str,',');
        this->mapDepth = strtol(str.c_str(),nullptr,10);

        tileMatrix.assign(mapWidth*mapHeight*mapDepth, -1);

        i = 0;
        j = 0;
        k = 0;

        while(getline(file,str,',')){

            at(i,j,k) = strtol(str.c_str(),nullptr,10) - 1;

            i++;

            if(i == mapWidth){
                i = 0;
                j++;
            }

            if(j == mapHeight){
                j = 0;
                k++;
            }

            if(k == mapDepth){
                break;
            }
        }
    }else{
        throw "Arquivo nao encontrado";
    }

    file.close();
}

void TileMap::setTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::at(int x,int y,int z){
    return tileMatrix[x + y*mapWidth + z*mapWidth*mapHeight];
}

void TileMap::render(int cameraX,int cameraY){

    int i;
    for(i=0;i<mapDepth;i++){
        renderLayer(i,cameraX,cameraY);
    }
}

void TileMap::renderLayer(int layer,int cameraX,int cameraY){

    int i,j;


    for(i=0;i<mapHeight;i++){
        for (j=0;j<mapWidth;j++){
            tileSet->render(at(i,j,layer),i*tileSet->getTileWidth() - cameraX,j*tileSet->getTileHeight() - cameraY);
        }
    }
}

int TileMap::getWidth(){
    return this->mapWidth;
}

int TileMap::getHeight(){
    return this->mapHeight;
}
int TileMap::getDepth(){
    return this->mapDepth;
}


