#ifndef STILLANIMATION_H
#define STILLANIMATION_H

#include <string>

#include "Camera.h"
#include "GameObject.h"
#include "Sound.h"
#include "Sprite.h"
#include "Timer.h"

class StillAnimation : public GameObject
{
public:
    StillAnimation(float,float,float,Sprite,float,bool,Sound);
    ~StillAnimation();
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
private:
	Timer endTimer;
	float timeLimit;
	bool oneTimeOnly;
	Sprite sp;
    Sound sound;

};

#endif // STILLANIMATION_H
