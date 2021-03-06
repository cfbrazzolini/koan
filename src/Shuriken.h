#ifndef SHURIKEN_H
#define SHURIKEN_H

#include "Item.h"

class Shuriken : public Item
{
private:
	bool used;
public:
    Shuriken();
    void update(float);
    void render();
    void render(float,float);
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    void use(int=0);
};

#endif // SHURIKEN_H
