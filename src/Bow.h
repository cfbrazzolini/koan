#ifndef BOW_H
#define BOW_H

#include "Item.h"

class Bow : public Item
{
public:
    Bow();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
};

#endif // BOW_H
