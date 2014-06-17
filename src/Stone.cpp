#include "Stone.h"

Stone::Stone(float x,float y,const std::string& file,const std::string& fileDestacada,int id) : spNormal(file),
																								spDestacada(fileDestacada),
                                                                                                sp(&spNormal),
                                                                                                stoneState(NORMAL),
																								id(id)
{

	rotation = 0;
	spDestacada.setScale(0.09);
	spNormal.setScale(0.09);
	box.setX(x - sp->getWidth()/2);
	box.setY(y - sp->getHeight()/2);
	box.setW(sp->getWidth());
	box.setH(sp->getHeight());
}


void Stone::update(float dt){

}

void Stone::render(){
    sp->render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
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

void Stone::selecionar(){
    if(stoneState == NORMAL){
		sp = &spDestacada;
        stoneState = DESTACADA;
	}else{
		sp = &spNormal;
        stoneState = NORMAL;
	}
}
