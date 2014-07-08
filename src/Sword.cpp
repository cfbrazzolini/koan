#include "Sword.h"

Sword::Sword() : used(false)
{	
	sp.open("img/armas/espada/espada3.png");
	sp.setScale(0.15);
	uses = 3;
	reach = 3;
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

bool Sword::isDead(){
	return uses == 0;
}

void Sword::notifyCollision(GameObject& other){

}

bool Sword::is(const std::string& type){
	return type == "Sword";
}

void Sword::use(){
    uses--;
	used = true;
}
