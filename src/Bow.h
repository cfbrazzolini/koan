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
    void render(float,float);
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    void use();
};

#endif // BOW_H
