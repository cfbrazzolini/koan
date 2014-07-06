#include "Shuriken.h"

Shuriken::Shuriken()
{
}

void Shuriken::update(float dt){

}

void Shuriken::render(){

}

bool Shuriken::isDead(){

}

void Shuriken::notifyCollision(GameObject& other){

}

bool Shuriken::is(const std::string& type){
	return type == "Shuriken";
}
