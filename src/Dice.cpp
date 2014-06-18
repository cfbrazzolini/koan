#include "Dice.h"

Dice::Dice(float x,float y) : 
sp("img/cube-dice.jpg"), 
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
}

void Dice::update(float dt){
	// printf("%d\n", valu/e);
	numero.setText(std::to_string(value));
}
 
void Dice::render(){
	// printf("%d\n", StateData::turn);
	printf("%d %d\n", StateData::turn, this->value);
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
	numero.render();
 }

bool Dice::isDead(){
	return false;
}

void Dice::notifyCollision(GameObject& other){

}

bool Dice::is(const std::string& type){
	return type == "Dice";
}