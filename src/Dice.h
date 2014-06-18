#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Camera.h"
#include "GameObject.h"
#include "Sprite.h"
#include "StateData.h"
#include "Text.h"

class Dice : public GameObject
{
public:
    Dice(float, float);
	void update(float);
	void render();
	bool isDead();
	void notifyCollision(GameObject&);
	bool is(const std::string&);

	int getValue();
	void setValue();
	static Dice& getInstance();

private:
	int value = 0;
	Sprite sp;
	Text numero;
};

#endif // DICE_H
