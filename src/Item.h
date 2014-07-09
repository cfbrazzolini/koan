#ifndef ITEM_H
#define ITEM_H

#include "Camera.h"
#include "GameObject.h"
#include "Sprite.h"

class Item : public GameObject
{
public:
    Item();
    virtual void update(float) = 0;
    virtual void render() = 0;
    void render(float,float);
    virtual bool isDead() = 0;
    virtual void notifyCollision(GameObject&) = 0;
    virtual bool is(const std::string&) = 0;
    int getUses();
    int getReach();
    int getDamage();
    bool isRechargeable();
    void setPos(float,float);
    virtual void use() = 0;
protected:
	int uses;
	int reach;
	int damage;
    Sprite sp;
    bool rechargeable;
};

#endif // ITEM_H
