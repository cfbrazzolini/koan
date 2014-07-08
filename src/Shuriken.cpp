#include "Shuriken.h"

Shuriken::Shuriken() : used(false)
{
	sp.open("img/armas/shuriken/shuriken 3.png");
	sp.setScale(0.15);
	uses = 3;
	reach = 5;
	damage = 1;
	rechargeable = true;
}

void Shuriken::update(float dt){
	if(uses != 0 && used){
        sp.open("img/armas/shuriken/shuriken " + std::to_string(uses) + ".png");
		used = false;
	}
}

void Shuriken::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

bool Shuriken::isDead(){
	return uses == 0;
}

void Shuriken::notifyCollision(GameObject& other){

}

bool Shuriken::is(const std::string& type){
	return type == "Shuriken";
}

void Shuriken::use(){
    uses--;
	used = true;
}

