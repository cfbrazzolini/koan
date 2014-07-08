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
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    void use();
};

#endif // SHURIKEN_H
