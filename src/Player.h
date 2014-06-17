#ifndef PLAYER_H
#define PLAYER_H

#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#include "Camera.h"
#include "CustomMath.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Point.h"
#include "StateData.h"
#include "Stone.h"
#include "Sprite.h"

#define PLAYER_FRAME_COUNT 8
#define PLAYER_FRAME_TIME 0.1
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
private:
	Sprite* sp;
	Sprite spFrente;
	Sprite spDireita;
	Sprite spEsquerda;
	Sprite spCostas;

	std::queue<TARGET_T> taskQueue;
	std::vector<Stone*> stoneArray;
	SDL_RendererFlip flip;
	int currentPos;
	int id;
};

#endif // PLAYER_H
