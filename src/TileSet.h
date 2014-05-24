#ifndef TILESET_H
#define TILESET_H

#include <string>

class TileSet
{
public:
    virtual ~TileSet();
    virtual void open(const std::string&) = 0;
    virtual void render(unsigned,float,float) = 0;
    int getTileWidth();
    int getTileHeight();
protected:
    int tileWidth;
    int tileHeight;


};

#endif // TILESET_H
