#ifndef SPRITE_H
#define SPRITE_H

#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <unordered_map>

#include "Game.h"


class Sprite{
public:
    Sprite();
    Sprite(const std::string&,int=1,float=1);
    virtual ~Sprite();
    void open(const std::string&);
    void setClip(int, int, int, int);
    void update(float);
    void render(int, int,float = 0);
    int getWidth();
    int getHeight();
    bool isOpen();
    static void clear();
    void setScaleX(float);
    void setScaleY(float);
    void setScale(float);
    void setFrame(int);
    void setFrameCount(int);
    void setFrameTime(float);

private:
    static std::unordered_map<std::string, SDL_Texture*> assetTable;
    SDL_Texture* texture;
    SDL_Rect dimensions;
    float scaleX;
    float scaleY;
    int frameCount;
    int currentFrame;
    float timeElapsed;
    float frameTime;
protected:
    SDL_Rect clipRect;
};


#endif // SPRITE_H
