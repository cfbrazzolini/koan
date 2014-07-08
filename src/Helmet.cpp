#include "Helmet.h"

Helmet::Helmet()
{
	sp.open("img/armas/capacete/capacete 5.png");
	sp.setScale(0.15);
	damage = 5;
	rechargeable = false;

}

void Helmet::update(float dt){

}

void Helmet::render(){

}

bool Helmet::isDead(){

}

void Helmet::notifyCollision(GameObject& other){

}

bool Helmet::is(const std::string& type){
	return type == "Helmet";
}
