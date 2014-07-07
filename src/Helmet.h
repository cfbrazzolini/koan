#ifndef HELMET_H
#define HELMET_H

#include "Item.h"

class Helmet : public Item
{
public:
    Helmet();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
};

#endif // HELMET_H
