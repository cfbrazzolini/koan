#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Text.h"
#include "Camera.h"
#include "GameObject.h"
#include "Sprite.h"
#include "StateData.h"


class Dice : public GameObject
{
public:
    Dice(float, float);
	 void update(float);
	 void render();
	 bool isDead();
	 void notifyCollision(GameObject&);
	 bool is(const std::string&);

	static int getValue();
	static void setValue();

private:
	static int value;
	Sprite sp;
	Text numero;
};

#endif // DICE_H
