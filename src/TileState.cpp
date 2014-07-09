#include "TileState.h"

TileState::TileState() :    bg("img/menu/menu_background.png"),
                            timer(),
                            /*text("font/Call me maybe.ttf",34,Text::TEXT_SOLID,"Press space to start",SDL_Color(),300,500),*/
                            /*show(true),*/
                            iniciarBg("img/menu/iniciar.png"),
                            historicoBg("img/menu/historico.png"),
                            music("audio/tituloPrincipal.mp3", -1)
{
	//text.setPos(Game::getInstance().getWindowWidth()/2,Game::getInstance().getWindowHeight()*5/6,true,true);
    music.play(1);
    iniciarBg.setScale(0.2);
    historicoBg.setScale(0.2);
    iniciarBox.setX(Game::getInstance().getWindowWidth()/2 - iniciarBg.getWidth()/2);
    iniciarBox.setY(Game::getInstance().getWindowHeight()*5/7 - iniciarBg.getHeight()/2);
    iniciarBox.setW(iniciarBg.getWidth());
    iniciarBox.setH(iniciarBg.getHeight());

    historicoBox.setX(Game::getInstance().getWindowWidth()/2 - historicoBg.getWidth()/2);
    historicoBox.setY(Game::getInstance().getWindowHeight()*6/7 - historicoBg.getHeight()/2);
    historicoBox.setW(historicoBg.getWidth());
    historicoBox.setH(historicoBg.getHeight());

}

void TileState::update(float dt){
	input();
	timer.update(dt);

	/*if(timer.getTime() >= DISPLAY_INTERVAL){
		show = !show;
		timer.restart();
	}*/
}

void TileState::render(){
    bg.render(200,0);

    /*if(show){
    	text.render();
    }*/

    iniciarBg.render(iniciarBox.getX() - Camera::pos.getX(),iniciarBox.getY() - Camera::pos.getY());
    historicoBg.render(historicoBox.getX() - Camera::pos.getX(),historicoBox.getY() - Camera::pos.getY());

	
}

void TileState::input(){

	auto& input = InputManager::getInstance();
    Point click;


    click.setX((float)input.getMouseX() + Camera::pos.getX());
    click.setY((float)input.getMouseY() + Camera::pos.getY());

    if(input.keyPress(ESCAPE_KEY) || input.shouldQuit()){
        hasRequestedQuit = true;
    }

    /*if(input.keyPress(SPACE_KEY)){
        Game::getInstance().push(new StageState());
    }*/
    if(input.mousePress(SDL_BUTTON_LEFT) && iniciarBox.hasPoint(click)){
        music.stop();
        Game::getInstance().push(new StageState());
    }
}
