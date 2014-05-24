#ifndef ENDSTATE_H
#define ENDSTATE_H

#include "Game.h"
#include "InputManager.h"
#include "Music.h"
#include "Sprite.h"
#include "StageState.h"
#include "State.h"
#include "StateData.h"
#include "Text.h"

class EndState : public State
{
public:
    EndState(StateData);
    void update(float);
    void render();
private:
	void input();

	Sprite bg;
	Music music;
	Text instruction;
	bool stop;
};

#endif // ENDSTATE_H
