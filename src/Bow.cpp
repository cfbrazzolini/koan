#include "Bow.h"

Bow::Bow() : used(false)
{
	sp.open("img/armas/arco/Arco10.png");
	sp.setScale(0.15);
	uses = 5;
	reach = 7;
	damage = 2;
	rechargeable = true;
}

void Bow::update(float dt){
	if(uses != 0 && used){
        sp.open("img/armas/arco/Arco" + std::to_string(uses) + ".png");
		used = false;
	}
}

void Bow::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

bool Bow::isDead(){
	return uses == 0;
}

void Bow::notifyCollision(GameObject& other){

}

bool Bow::is(const std::string& type){
	return type == "Bow";
}

void Bow::use(){
    uses--;
	used = true;
}
