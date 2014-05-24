#include "Sprite.h"


std::unordered_map<std::string,SDL_Texture*> Sprite::assetTable;

Sprite::Sprite(){
    texture = nullptr;
    scaleX = 1;
    scaleY = 1;
    frameTime = 1;
    frameCount = 1;
    currentFrame = 0;
    timeElapsed = 0;
}

Sprite::Sprite(const std::string& file, int frameCount,float frameTime){
    texture = nullptr;
    scaleX = 1;
    scaleY = 1;

    this->frameTime = frameTime;
    this->frameCount = frameCount;
    currentFrame = 0;
    timeElapsed = 0;
    open(file);
}

Sprite::~Sprite(){
    
}

void Sprite::open(const std::string& file){

    if(assetTable.find(file) == assetTable.end()){
        if((texture=IMG_LoadTexture(Game::getInstance().getRenderer(), file.c_str()))==nullptr){
            printf("nao foi possivel carregar a texture %s\n", file.c_str());
            printf("%s\n",SDL_GetError());
            return;
        }else{
            assetTable.emplace(file,texture);
        }

    }else{
        texture = assetTable[file];
    }
   
    SDL_QueryTexture(texture, nullptr, nullptr, &dimensions.w, &dimensions.h);
    setClip(0,0, dimensions.w/frameCount, dimensions.h);
}

void Sprite::setClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}


void Sprite::update(float dt){

    timeElapsed += dt;
    if(timeElapsed >= frameTime){
        timeElapsed = 0;
        currentFrame = (++currentFrame) % frameCount;
        setClip(currentFrame*(dimensions.w/frameCount),clipRect.y,clipRect.w,clipRect.h);
    }
}

void Sprite::render(int x, int y,float angle){

    if(!isOpen()){
        return;
    }
    SDL_Rect dstRect;

    dstRect = dimensions;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = clipRect.w*scaleX;
    dstRect.h = clipRect.h*scaleY;

    SDL_RenderCopyEx(Game::getInstance().getRenderer(), texture, &clipRect, &dstRect,angle,NULL,SDL_FLIP_NONE);
}

int Sprite::getWidth(){
    return dimensions.w/frameCount * scaleX;
}

int Sprite::getHeight(){
    return dimensions.h*scaleY;
}

bool Sprite::isOpen(){
    return texture != nullptr;
}


void Sprite::clear(){
    
    for ( auto it = assetTable.begin(); it!= assetTable.end(); ++it ){
       SDL_DestroyTexture(it->second);
    }

    assetTable.clear();
}


void Sprite::setScaleX(float scale){
    scaleX = scale;
}

void Sprite::setScaleY(float scale){
    scaleY = scale;
}

void Sprite::setScale(float scale){

    scaleX = scale;
    scaleY = scale;

}

void Sprite::setFrame(int frame){

    currentFrame = frame % frameCount;
    setClip(currentFrame*(dimensions.w/frameCount),clipRect.y,clipRect.w,clipRect.h);
}

void Sprite::setFrameCount(int frameCount){
    this->frameCount = frameCount;
}

void Sprite::setFrameTime(float frameTime){
    this->frameTime = frameTime;
}

