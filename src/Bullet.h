#ifndef BULLET_H
#define BULLET_H

#include <cmath>
#include <string>

#include "Camera.h"
#include "CustomMath.h"
#include "GameObject.h"
#include "Point.h"
#include "Sprite.h"

class Bullet : public GameObject
{
public:
    Bullet(float,float,float,float,float,const std::string& sprite,int,float,std::string);
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    std::string getShooter();
private:
	Sprite sp;
	Point speed;
	float distanceLeft;
	std::string shooter;
};

#endif // BULLET_H
