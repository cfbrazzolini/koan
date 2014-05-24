#ifndef GAME_H
#define GAME_H

#include <ctime>
#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stack>
#include <string>

#include "GameObject.h"
#include "InputManager.h"
#include "State.h"

class Game
{
public:
    Game(const std::string&,int,int);
    ~Game();
    SDL_Renderer* getRenderer();
    static Game& getInstance();
    static State& getCurrentState();
    void push(State*);
    void run();
    int getWindowWidth();
    int getWindowHeight();
private:
	void calculateDeltaTime();
	int frameStart;
	float dt;
	static Game* instance;
	State* storedState;
	SDL_Window* window;
	SDL_Renderer* renderer;
	static std::stack<std::unique_ptr<State>> stateStack;
};

#endif // GAME_H
