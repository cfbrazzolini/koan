#ifndef PLAYER_H
#define PLAYER_H

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>

#include "ActionMenu.h"
#include "Bow.h"
#include "Camera.h"
#include "CustomMath.h"
#include "Dice.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Globals.h"
#include "Helmet.h"
#include "Hud.h"
#include "Item.h"
#include "Music.h"
#include "Point.h"
#include "question.h"
#include "Shuriken.h"
#include "Sprite.h"
#include "StateData.h"
#include "Stone.h"
#include "Sword.h"
#include "Trap.h"


#define PLAYER_FRAME_COUNT 8
#define PLAYER_FRAME_TIME 0.1
#define PLAYER_HP 20
#define PLAYER_ITEM_LIMIT 3
#define PLAYER_SPEED 100


typedef struct target{
	Point pos;
	int id;
}TARGET_T;

class Player : public GameObject
{
public:
    Player(int,int,std::unordered_map<int,Stone*>,const std::string&);
    ~Player();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    int getId();
    int getHp();
    void hit(int);
    std::vector<Item*>* getItens();
    std::string& getColor();
    void setPlayerArray(std::vector<Player*>*);
private:
	enum PlayerState {STANDBY,MOVING,ATTACKING,STAND};
	Sprite* sp;
	Sprite spFrente;
	Sprite spDireita;
	Sprite spEsquerda;
	Sprite spCostas;
	ActionMenu actionMenu;

	std::queue<TARGET_T> taskQueue;
	std::vector<int> validStones;
	std::unordered_map<int,Stone*> stoneArray;
    std::vector<Item*> itemArray;
    std::vector<Player*>* playerArray;
	SDL_RendererFlip flip;
	PlayerState playerState;
	bool moved;
	bool stood;
	bool attacked;
	bool jogouDado;
	int hp;
	int currentPos;
	int id;
	int movementsRemaining;
    std::string color;
    bool showActionMenu;

    Music music;
    Music espada, arco, shuriken;
    Music vitoria, derrota;
    Music salto;
};

#endif // PLAYER_H
