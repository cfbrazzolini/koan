#ifndef STONE_H
#define STONE_H

#include <string>

#include "Camera.h"
#include "GameObject.h"
#include "Sprite.h"

class Stone : public GameObject
{
public:
    Stone(float,float,const std::string&,const std::string&,int);
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    int getId();
    void selecionar();
private:
    Sprite* sp;
	Sprite spNormal;
	Sprite spDestacada;
    enum StoneState {NORMAL,DESTACADA};
    StoneState stoneState;
	int id;
};

#endif // STONE_H
