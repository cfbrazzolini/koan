#include "Stone.h"

Stone::Stone(float x,float y,const std::string& file,int id) : sp(file),id(id)
{

	rotation = 0;
	sp.setScale(0.09);
	box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

}


void Stone::update(float dt){

}

void Stone::render(){
    sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

bool Stone::isDead(){
    return false;
}

void Stone::notifyCollision(GameObject& other){

}

bool Stone::is(const std::string& type){
	return type == "Stone";
}

int Stone::getId(){
	return id;
}