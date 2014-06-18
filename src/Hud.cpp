#include "Hud.h"

#include <iostream>

Hud::Hud(float x, float y, int id) : 	sp("img/hp_itens/barradomongevermelho.PNG"),
													hpSp("img/hp_itens/barras/20vida.PNG"),
                                                	id(id)
{
	sp.setScale(0.1);
	hpSp.setScale(0.1);

	if(id == 0){
		box.setX(0);
		box.setY(0);
	}else{
        box.setX(Game::getInstance().getWindowWidth() - sp.getWidth());
		box.setY(0);
	}

	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

    lastHp = StateData::playerHp[id];
    rotation = 0;
}

void Hud::update(float dt){

    //std::cout << "last hp:" << lastHp << "player hp" << StateData::playerHp[id] << std::endl;

	if(lastHp != StateData::playerHp[id]){
		lastHp = StateData::playerHp[id];
		//std::cout << "img/hp_itens/barras/" << lastHp << "vida.PNG" << std::endl;
        hpSp.open("img/hp_itens/barras/" + std::to_string(lastHp) + "vida.PNG");
		hpSp.setScale(0.1);
	}

}

void Hud::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
    hpSp.render(box.getX() - Camera::pos.getX() + hpSp.getWidth()/3 ,box.getY() - Camera::pos.getY() + hpSp.getHeight()- 2);
}

bool Hud::isDead(){
	return false;
}

void Hud::notifyCollision(GameObject& other){

}

bool Hud::is(const std::string& type){
	return type == "Hud";
}
