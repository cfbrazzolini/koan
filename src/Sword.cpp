#include "Sword.h"

Sword::Sword() : used(false)
{	
	sp.open("img/armas/espada/espada3.png");
	sp.setScale(0.15);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());
	uses = 3;
	reach = 2;
	damage = 5;
	rechargeable = false;
}

void Sword::update(float dt){
	
	if(uses != 0 && used){
        sp.open("img/armas/espada/espada" + std::to_string(uses) + ".png");
		used = false;
	}

}

void Sword::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

void Sword::render(float x, float y){
	

	if(x == 0){
		sp.render(x - Camera::pos.getX(),y - Camera::pos.getY());
	}else{
		sp.render(x - sp.getWidth() - Camera::pos.getX(),y - Camera::pos.getY());
	}
}

bool Sword::isDead(){
	return uses == 0;
}

void Sword::notifyCollision(GameObject& other){

}

bool Sword::is(const std::string& type){
	return type == "Sword" || type == "Arma";
}

void Sword::use(int value){
    uses--;
	used = true;
}
