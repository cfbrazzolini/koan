#include "Helmet.h"

Helmet::Helmet() : used(false)
{
	sp.open("img/armas/capacete/capacete 5.png");
	sp.setScale(0.15);
	damage = 5;
	rechargeable = false;

}

void Helmet::update(float dt){
	if(damage > 0 && used){
        sp.open("img/armas/capacete/capacete " + std::to_string(damage) + ".png");
		used = false;
	}
}

void Helmet::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

void Helmet::render(float x, float y){

	if(x == 0){
		sp.render(x - Camera::pos.getX(),y - Camera::pos.getY());
	}else{
		sp.render(x - sp.getWidth() - Camera::pos.getX(),y - Camera::pos.getY());
	}
}

bool Helmet::isDead(){
	return damage <= 0;
}

void Helmet::notifyCollision(GameObject& other){

}

bool Helmet::is(const std::string& type){
	return type == "Helmet" || type == "Armor";
}

void Helmet::use(int value){
	damage -= value;
	used = true;
}
