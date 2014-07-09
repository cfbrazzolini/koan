#ifndef HUD_H
#define HUD_H

#include <string>

#include "Camera.h"
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Sprite.h"
#include "StateData.h"

class Hud : public GameObject
{
public:
    Hud(float,float,int,GameObject*);
    ~Hud();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
	bool is(const std::string&);
private:
	GameObject* player;
    std::vector<Item*>* itemArray;
	Sprite sp;
	Sprite hpSp;
	int id;
	int lastHp;
	

};

#endif // HUD_H
