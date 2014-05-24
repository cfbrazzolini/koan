#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>
#include <unordered_map>

#include "Rect.h"

#define N_MOUSE_BUTTONS 	6
#define LEFT_ARROW_KEY    	SDLK_LEFT
#define RIGHT_ARROW_KEY   	SDLK_RIGHT
#define UP_ARROW_KEY      	SDLK_UP
#define DOWN_ARROW_KEY    	SDLK_DOWN
#define ESCAPE_KEY        	SDLK_ESCAPE
#define SPACE_KEY        	SDLK_SPACE
#define LEFT_MOUSE_BUTTON 	SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON 	SDL_BUTTON_RIGHT
#define X_KEY 				SDLK_x
#define A_KEY               SDLK_a
#define W_KEY               SDLK_w
#define D_KEY               SDLK_d
#define S_KEY               SDLK_s
#define Z_KEY               SDLK_z

class InputManager
{
public:
	static InputManager& getInstance();
    void update();

    bool keyPress(int);
    bool keyRelease(int);
    bool isKeyDown(int);
    bool mousePress(int);
    bool mouseRelease(int);
    bool isMouseDown(int);

    int getMouseX();
    int getMouseY();

    bool isMouseInside(Rect);
    bool shouldQuit();
    
private:
	enum InputState{RELEASED,JUST_RELEASED,PRESSED,JUST_PRESSED};
	InputManager();
	~InputManager();
	InputState mouseState[N_MOUSE_BUTTONS];
	std::unordered_map<int,InputState> keyState;
	bool quitGame;
	int mouseX;
	int mouseY;

};

#endif // INPUTMANAGER_H
