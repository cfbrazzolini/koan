#ifndef TILESTATE_H
#define TILESTATE_H

#include "Camera.h"
#include "InputManager.h"
#include "Sprite.h"
#include "StageState.h"
#include "State.h"
#include "Text.h"
#include "Timer.h"

#define DISPLAY_INTERVAL 0.5



class TileState : public State
{
public:
    TileState();
    void update(float);
    void render();
private:
	void input();

	Sprite bg;
	Timer timer;
	Text text;
	bool show;
};

#endif // TILESTATE_H
