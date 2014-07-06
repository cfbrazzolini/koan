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