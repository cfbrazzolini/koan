#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

#include "Rect.h"

class GameObject
{
public:
    virtual ~GameObject();
    virtual void update(float) = 0;
    virtual void render() = 0;
    virtual bool isDead() = 0;
    virtual void notifyCollision(GameObject&) = 0;
    virtual bool is(const std::string&) = 0;

    Rect box;
    float rotation;
};

#endif // GAMEOBJECT_H
