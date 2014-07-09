#ifndef BOW_H
#define BOW_H

#include "Item.h"

class Bow : public Item
{
private:
	bool used;
public:
    Bow();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    void use();
};

#endif // BOW_H
