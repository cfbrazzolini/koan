#ifndef DICE_H
#define DICE_H

#include <string>
#include <iostream>

#include "Text.h"
#include "Camera.h"
#include "GameObject.h"
#include "Sprite.h"
#include <stdlib.h>


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

private:
	int value = 0;
	Sprite sp;
	Text numero;
};

#endif // DICE_H
