#ifndef STAGESTATE_H
#define STAGESTATE_H

#include <cstdio>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>

#include "BlockTileSet.h"
#include "Camera.h"
#include "Colission.h"
#include "CustomMath.h"
#include "Dice.h"
#include "EndState.h"
#include "Game.h"
#include "Map.h"
#include "Music.h"
#include "Player.h"
#include "Sprite.h"
#include "State.h"
#include "StateData.h"
#include "Stone.h"
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
    Map map;
    Music music;
    std::unordered_map<int,Stone*> stoneArray;

    // Dice dice;
};

#endif // STAGESTATE_H
