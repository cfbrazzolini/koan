#include "Dice.h"

Dice::Dice(float x,float y) : 
sp("img/Dado/dado.png",6), 
numero("font/Call me maybe.ttf",34,Text::TEXT_SOLID,std::to_string(value),SDL_Color(),0,0)
{
	srand (time(NULL));
	sp.setScale(0.1);
	box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

	value = (rand() % 6) + 1;
	numero.setText(std::to_string(value));
	numero.setPos(box.getCenter().getX() - Camera::pos.getX(),box.getCenter().getY() - Camera::pos.getY(),true,true);

}

int Dice::getValue(){
	return value;
}

void Dice::setValue(){
	value = (rand() % 6) + 1;
	sp.setFrame(value-1);
}

void Dice::update(float dt){
	// printf("%d\n", valu/e);
	numero.setText(std::to_string(value));
	sp.setFrame(value-1);
}
 
void Dice::render(){
	// printf("%d\n", StateData::turn);
	//printf("%d %d\n", StateData::turn, this->value);
	sp.render(StateData::turn*(Game::getInstance().getWindowWidth()-sp.getWidth()) - Camera::pos.getX(),Game::getInstance().getWindowHeight()/2 - sp.getHeight()/2 - Camera::pos.getY());
    
	
    if(StateData::turn == 0){
    	numero.setPos(sp.getWidth()/2 - Camera::pos.getX(),Game::getInstance().getWindowHeight()/2  - Camera::pos.getY(),true,true);
    }else{
    	numero.setPos(StateData::turn*(Game::getInstance().getWindowWidth()-sp.getWidth()/2) - Camera::pos.getX(),Game::getInstance().getWindowHeight()/2 - Camera::pos.getY(),true,true);
    }
	//numero.render();
 }

bool Dice::isDead(){
	return false;
}

void Dice::notifyCollision(GameObject& other){

}

bool Dice::is(const std::string& type){
	return type == "Dice";
}

Dice& Dice::getInstance(){
	static Dice instance(750,550);

	return instance;
}
