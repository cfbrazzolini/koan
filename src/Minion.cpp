#include "Minion.h"

Minion::Minion(GameObject* minionCenter, float angleOffset) : sp("img/minion.png"),center(minionCenter),angle(angleOffset){

	//sp.setScale(0.5);
	rotation = -1*(90 - fmod(CustomMath::radToDeg(angle),90));
	
	box.setX(center->box.getCenter().getX() + RADIUS*cos(angle) - sp.getWidth()/2);
	box.setY(center->box.getCenter().getY() + RADIUS*sin(angle)  - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());



}

void Minion::update(float dt){

	angle += ANGULAR_SPEED * dt;
	rotation = -1*(90 - fmod(CustomMath::radToDeg(angle),90));
	
	box.setX(center->box.getCenter().getX() + RADIUS*cos(angle) - sp.getWidth()/2);
	box.setY(center->box.getCenter().getY() + RADIUS*sin(angle)  - sp.getHeight()/2);
}

void Minion::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
}

bool Minion::isDead(){
	return false;
}

void Minion::shoot(float x,float y){

	float angle;
	int radius = 40;
	Point target,bullet_origin;
	auto &game = Game::getInstance();

    target.setX(x - box.getCenter().getX());
    target.setY(y - box.getCenter().getY());

    angle = target.vectorInclination();

    bullet_origin.setX(box.getCenter().getX() + radius*cos(angle));
    bullet_origin.setY(box.getCenter().getY() + radius*sin(angle));

    Bullet* bullet = new Bullet(bullet_origin.getX(),bullet_origin.getY(),angle,MINION_BULLET_SPEED,MINION_BULLET_RANGE,"img/minionbullet.png",MINION_BULLET_FRAME_COUNT,MINION_BULLET_FRAME_TIME,"Minion");
    game.getCurrentState().addObject(bullet);
}

void Minion::notifyCollision(GameObject& other){
	
}

bool Minion::is(const std::string& type){
	return type == "Minion";
}
