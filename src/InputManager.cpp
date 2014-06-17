#include "InputManager.h"



InputManager& InputManager::getInstance(){

	static InputManager instance;

	return instance;
}


InputManager::InputManager(){

	int i;

	for(i=0;i<N_MOUSE_BUTTONS;i++){
		mouseState[i] = RELEASED;
	}
}

void InputManager::update(){

  	SDL_Event event;
    int i;


    quitGame = false;

    


    for(i=0;i<N_MOUSE_BUTTONS;i++){
    	switch(mouseState[i]){
    		case JUST_PRESSED:
    			mouseState[i] = PRESSED;
    			break;
			case JUST_RELEASED:
				mouseState[i] = RELEASED;
				break;
    	}
    }

    for(auto it = keyState.begin();it != keyState.end();++it){
    	switch(it->second){
    		case JUST_PRESSED:
    			it->second = PRESSED;
    			break;
			case JUST_RELEASED:
				it->second = RELEASED;
				break;
    	}
    }




    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

    	switch(event.type){

            case SDL_QUIT:
                quitGame = true;
                break;

            case SDL_MOUSEBUTTONDOWN:
            	mouseState[event.button.button] = JUST_PRESSED;
                break;

            case SDL_MOUSEBUTTONUP:
                mouseState[event.button.button] = JUST_RELEASED;
                break;

            case SDL_KEYDOWN:
            	if (!event.key.repeat)
                	keyState[event.key.keysym.sym] = JUST_PRESSED;
                break;

            case SDL_KEYUP:
                keyState[event.key.keysym.sym] = JUST_RELEASED;
                break;
        }
    }

    SDL_GetMouseState(&mouseX, &mouseY);

}

bool InputManager::keyPress(int key){

	if(keyState[key] == JUST_PRESSED){
		return true;
	}else{
		return false;
	}
}

bool InputManager::keyRelease(int key){

	if(keyState[key] == JUST_RELEASED){
		return true;
	}else{
		return false;
	}
}


bool InputManager::isKeyDown(int key){

	if(keyState[key] == PRESSED || keyState[key] == JUST_PRESSED){
		return true;
	}else{
		return false;
	}
}


bool InputManager::mousePress(int buttom){

	if(mouseState[buttom] == JUST_PRESSED){
		return true;
	}else{
		return false;
	}
}

bool InputManager::mouseRelease(int buttom){

	if(mouseState[buttom] == JUST_RELEASED){
		return true;
	}else{
		return false;
	}
}


bool InputManager::isMouseDown(int buttom){

	if(mouseState[buttom] == PRESSED || mouseState[buttom] == JUST_PRESSED){
		return true;
	}else{
		return false;
	}
}

int InputManager::getMouseX(){
	return mouseX;
}

int InputManager::getMouseY(){
	return mouseY;
}

bool InputManager::isMouseInside(Rect rect){
	return rect.isInside((float)mouseX,(float)mouseY);
}

bool InputManager::shouldQuit(){
	return quitGame;
}

InputManager::~InputManager(){

}
