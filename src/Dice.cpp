#include "Dice.h"

Dice::Dice(float x,float y) :sp("img/cube-dice.jpg"), rotation(0) {
	srand (time(NULL));
	sp.setScale(0.01);
	box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());
}

int Dice::getValue(){
	return value;
}

void Dice::update(float dt){
	value = rand() % 7;
	return value;
}
 
void Dice::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
 }

bool Dice::isDead(){
	return false;
}

void Dice::notifyCollision(GameObject& other){

}

bool Dice::is(const std::string& type){
	return type == "Dice";
}