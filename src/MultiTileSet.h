#ifndef MULTITILESET_H
#define MULTITILESET_H


#include <string>
#include <vector>

#include "Sprite.h"
#include "TileSet.h"

class MultiTileSet : public TileSet
{
public:
    MultiTileSet(int,int);
    ~MultiTileSet();
    void open(const std::string&);
    void render(unsigned,int,int);
protected:
    std::vector<Sprite> tileArray;
};

#endif // MULTITILESET_H
