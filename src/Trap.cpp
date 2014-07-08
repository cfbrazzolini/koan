#include "Trap.h"

Trap::Trap()
{
	sp.open("img/armas/armadilha/armadilha.png");
	sp.setScale(0.15);
	uses = 1;
	reach = 0;
	damage = 3;
	rechargeable = false;
}

void Trap::update(float dt){

}

void Trap::render(){

}

bool Trap::isDead(){

}

void Trap::notifyCollision(GameObject& other){

}

bool Trap::is(const std::string& is){

}

void Trap::activate(){

}

bool Trap::isRechargeable(){
	return false;
}