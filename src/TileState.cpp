#include "TileState.h"

TileState::TileState() : bg("img/title.jpg"),timer(),text("font/Call me maybe.ttf",34,Text::TEXT_SOLID,"Press space to start",SDL_Color(),300,500),show(true)
{
	text.setPos(Game::getInstance().getWindowWidth()/2,Game::getInstance().getWindowHeight()*5/6,true,true);
}

void TileState::update(float dt){
	input();
	timer.update(dt);

	if(timer.getTime() >= DISPLAY_INTERVAL){
		show = !show;
		timer.restart();
	}
}

void TileState::render(){
    bg.render(0,0);

    if(show){
    	text.render();
    }
	
}

void TileState::input(){

	auto& input = InputManager::getInstance();

    if(input.keyPress(ESCAPE_KEY) || input.shouldQuit()){
        hasRequestedQuit = true;
    }

    if(input.keyPress(SPACE_KEY)){
        Game::getInstance().push(new StageState());
    }
}
