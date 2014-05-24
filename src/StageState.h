#ifndef STAGESTATE_H
#define STAGESTATE_H

#include <fstream>

#include "Alien.h"
#include "BlockTileSet.h"
#include "Camera.h"
#include "Colission.h"
#include "CustomMath.h"
#include "EndState.h"
#include "Game.h"
#include "Music.h"
#include "Penguins.h"
#include "Sprite.h"
#include "State.h"
#include "TileMap.h"


class StageState : public State
{
public:
    StageState();
    ~StageState();
    void update(float);
    void render();
private:
	void input();
	Sprite bg;
	BlockTileSet tileSet;
	TileMap tileMap;
    Music music;
};

#endif // STAGESTATE_H
