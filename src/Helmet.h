#ifndef HELMET_H
#define HELMET_H

#include "Item.h"

class Helmet : public Item
{
private:
	bool used;
public:
    Helmet();
    void update(float);
    void render();
    void render(float,float);
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    void use(int=0);
};

#endif // HELMET_H
