#ifndef DICE_H
#define DICE_H

#include <iostream>
<<<<<<< HEAD
#include <string>
#include <stdlib.h>
=======
#include <stdlib.h>
#include <string>
>>>>>>> c57bd773b69066a29430242fc42211b36ee84b42

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

<<<<<<< HEAD
	static int getValue();
	static void setValue();
=======
	int getValue();
	void setValue();
	static Dice& getInstance();
>>>>>>> c57bd773b69066a29430242fc42211b36ee84b42

private:
	static int value;
	Sprite sp;
	Text numero;
};

#endif // DICE_H
