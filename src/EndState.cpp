#include "EndState.h"

EndState::EndState(StateData stateData) : instruction("font/Call me maybe.ttf",34,Text::TEXT_SOLID,"Press space to try again or ESC to exit",SDL_Color(),0,0)
{

	if(stateData.playerVictory == true){
        bg.open("img/win.jpg");
        music.open("audio/endStateWin.ogg");
        
	}else{
        bg.open("img/lose.jpg");
        music.open("audio/endStateLose.ogg");
     
	}
	music.play(-1);
    stop = false;

	instruction.setPos(Game::getInstance().getWindowWidth()/2,Game::getInstance().getWindowHeight()*5/6,true,true);

}

void EndState::update(float dt){
	input();
}

void EndState::input(){

    auto& input = InputManager::getInstance();

    if( input.shouldQuit()){
        hasRequestedQuit = true;
    }

    if(input.keyPress(ESCAPE_KEY)){
        hasRequestedDelete = true;
    }

    if(input.keyPress(SPACE_KEY)){
    	hasRequestedDelete = true;
        Game::getInstance().push(new StageState());
    }

    if(stop){
    	music.stop();
    }
}

void EndState::render(){
    bg.render(0,0);
	instruction.render();
}
