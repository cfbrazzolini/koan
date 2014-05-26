#ifndef PLAYER_H
#define PLAYER_H

#include <queue>

#include "Camera.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Point.h"
#include "Sprite.h"

#define PLAYER_SPEED 100

class Player : public GameObject
{
public:
    Player(float,float);
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
private:
	Sprite sp;
	std::queue<Point> taskQueue;
};

#endif // PLAYER_H
