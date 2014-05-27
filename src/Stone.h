#ifndef STONE_H
#define STONE_H

#include <string>

#include "Camera.h"
#include "GameObject.h"
#include "Sprite.h"

class Stone
{
public:
    Stone();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&)
private:
	 Sprite sp;
};

#endif // STONE_H
