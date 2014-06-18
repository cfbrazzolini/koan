#ifndef PLAYER_H
#define PLAYER_H

#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#include "Camera.h"
#include "CustomMath.h"
#include "Dice.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Hud.h"
#include "Point.h"
#include "Sprite.h"
#include "StateData.h"
#include "Stone.h"


#define PLAYER_FRAME_COUNT 8
#define PLAYER_FRAME_TIME 0.1
#define PLAYER_HP 20
#define PLAYER_SPEED 100


typedef struct target{
	Point pos;
	int id;
}TARGET_T;

class Player : public GameObject
{
public:
    Player(int,int,std::vector<Stone*>);
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    int getId();
    int getHp();
private:
	enum PlayerState {STANDBY,MOVING,ATTACKING};
	Sprite* sp;
	Sprite spFrente;
	Sprite spDireita;
	Sprite spEsquerda;
	Sprite spCostas;

	std::queue<TARGET_T> taskQueue;
	std::vector<int> validStones;
	std::vector<Stone*> stoneArray;
	SDL_RendererFlip flip;
	PlayerState playerState;
	bool moved;
	bool attacked;
	bool jogouDado;
	int hp;
	int currentPos;
	int id;
	int movementsRemaining;
};

#endif // PLAYER_H
