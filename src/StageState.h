#ifndef STAGESTATE_H
#define STAGESTATE_H

#include <cstdio>
#include <fstream>
#include <memory>
#include <vector>

#include "BlockTileSet.h"
#include "Camera.h"
#include "Colission.h"
#include "CustomMath.h"
#include "EndState.h"
#include "Game.h"
#include "Music.h"
#include "Player.h"
#include "Sprite.h"
#include "State.h"
#include "Stone.h"
#include "TileMap.h"
#include "Dice.h"

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
	//BlockTileSet tileSet;
	//TileMap tileMap;
    Music music;
    std::vector<Stone*> stoneArray;
};

#endif // STAGESTATE_H
