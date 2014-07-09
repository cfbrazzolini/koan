#include "Item.h"

Item::Item()
{
}

int Item::getUses(){
	return uses;
}

int Item::getReach(){
	return reach;
}

int Item::getDamage(){
	return damage;
}

bool Item::isRechargeable(){
	return rechargeable;
}

void Item::setPos(float x,float y){
	box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
}

void Item::render(float x, float y){
	

	if(x == 0){
		sp.render(x - Camera::pos.getX(),y - Camera::pos.getY());
	}else{
		sp.render(x - sp.getWidth() - Camera::pos.getX(),y - Camera::pos.getY());
	}
}