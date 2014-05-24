#ifndef BLOCKTILESET_H
#define BLOCKTILESET_H

#include <string>

#include "Sprite.h"
#include "TileSet.h"

class BlockTileSet : public TileSet
{
public:
    BlockTileSet(int,int,const std::string&);
    void open(const std::string&);
    void render(unsigned,float,float);
private:
	Sprite tileSet;
	int rows;
	int columns;
};

#endif // BLOCKTILESET_H
