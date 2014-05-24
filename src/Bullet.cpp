#include "Bullet.h"

Bullet::Bullet(float x,float y,float angle,float speed,float maxDistance,const std::string& sprite,int frameCount,float frameTime,const std::string shooter) : sp(sprite,frameCount,frameTime){

	box.setX(x - sp.getWidth()/2);
    box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

    this->shooter = shooter;

    rotation = CustomMath::radToDeg(angle);
	distanceLeft = maxDistance;

	this->speed.setX(speed * cos(angle));
	this->speed.setY(speed * sin(angle));
}

void Bullet::update(float dt){
	box.sumPoint(speed.vectorXScalar(dt));
    distanceLeft -= speed.vectorXScalar(dt).vectorMagnitude();
    sp.update(dt);
}

void Bullet::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
}

bool Bullet::isDead(){
	return distanceLeft <= 0;
}

std::string Bullet::getShooter(){
    return shooter;
}


void Bullet::notifyCollision(GameObject& other){
	
	if(other.is("Alien") && shooter == "Penguins"){
		distanceLeft = 0;
	}
	else if(other.is("Penguins") && shooter == "Minion"){
		distanceLeft = 0;
	}
}

bool Bullet::is(const std::string& type){
	return type == "Bullet";
}

