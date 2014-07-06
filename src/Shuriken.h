#ifndef SHURIKEN_H
#define SHURIKEN_H

#include "Item.h"

class Shuriken : public Item
{
public:
    Shuriken();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
};

#endif // SHURIKEN_H
