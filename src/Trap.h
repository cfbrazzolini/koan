#ifndef TRAP_H
#define TRAP_H

#include "Item.h"

class Trap : public Item
{
public:
    Trap();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    void activate();
    bool isRechargeable();
};

#endif // TRAP_H
