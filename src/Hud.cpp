#include "Hud.h"

#include <iostream>

Hud::Hud(float x, float y, int id,GameObject* player) :
													hpSp("img/hp_itens/barras/20vida.png"),
                                                	id(id),
                                                	player(player)

{
    sp.open("img/hp_itens/barradomonge" + ((Player*)player)->getColor() + ".png");
	sp.setScale(0.15);
	hpSp.setScale(0.15);

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
    itemArray = ((Player*)player)->getItens();
}

void Hud::update(float dt){

    //std::cout << "last hp:" << lastHp << "player hp" << StateData::playerHp[id] << std::endl;
    for(auto i = 0;i < itemArray->size();i++){
        itemArray->at(i)->setPos(box.getCenter().getX() - 18 +45*i,box.getCenter().getY() + 5);
    }

	if(lastHp != StateData::playerHp[id]){
		lastHp = StateData::playerHp[id];
		//std::cout << "img/hp_itens/barras/" << lastHp << "vida.PNG" << std::endl;
        hpSp.open("img/hp_itens/barras/" + std::to_string(lastHp) + "vida.png");
		hpSp.setScale(0.15);
	}

    for(auto i = 0;i < itemArray->size();i++){
        itemArray->at(i)->update(dt);
	}

}

void Hud::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
    hpSp.render(box.getX() - Camera::pos.getX() + hpSp.getWidth()/3 ,box.getY() - Camera::pos.getY() + hpSp.getHeight()- 2);

	for(auto i = 0;i<itemArray->size();i++){
         itemArray->at(i)->render();
	}

}

bool Hud::isDead(){
	return false;
}

void Hud::notifyCollision(GameObject& other){

}

bool Hud::is(const std::string& type){
	return type == "Hud";
}
