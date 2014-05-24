#ifndef TILEMAP_H
#define TILEMAP_H

#include <fstream>
#include <string>
#include <vector>

#include "TileSet.h"

class TileMap
{
public:
    TileMap(int,int,int,TileSet* = nullptr);
    TileMap(const std::string&,TileSet* = nullptr);
    void load(const std::string&);
    void setTileSet(TileSet*);
    int& at(int,int,int = 0);
    void render(int = 0,int = 0);
    void renderLayer(int,int=0,int=0);
    int getWidth();
    int getHeight();
    int getDepth();
private:
    std::vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;

};

#endif // TILEMAP_H
