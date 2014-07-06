#include "Bow.h"

Bow::Bow()
{
	rechargeable = true;
}

void Bow::update(float dt){

}

void Bow::render(){

}

bool Bow::isDead(){

}

void Bow::notifyCollision(GameObject& other){

}

bool Bow::is(const std::string& type){
	return type == "Bow";
}