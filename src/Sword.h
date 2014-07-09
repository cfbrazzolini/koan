#ifndef SWORD_H
#define SWORD_H

#include "Item.h"

class Sword : public Item
{
public:
    Sword();
    void update(float);
    void render();
     void render(float,float);
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    void use(int=0);
private:
	bool used;
};

#endif // SWORD_H
