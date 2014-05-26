#include "Player.h"

Player::Player(float x,float y) : sp("img/mestre.png")
{
	sp.setScale(0.01);
	rotation = 0;

	box.setX(x - sp.getWidth()/2);
	box.setY(y- sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());
}


void Player::update(float dt){

	auto& input = InputManager::getInstance();
	Point speed,pos;
	Point click;

    if (input.mousePress(SDL_BUTTON_RIGHT)){
        click.setX((float)input.getMouseX() + Camera::pos.getX());
        click.setY((float)input.getMouseY() + Camera::pos.getY());

	   taskQueue.push(click);
	}

	if(!taskQueue.empty()){
		pos = taskQueue.front();

		if(box.getCenter().computeDistance(pos) < 5){
			taskQueue.pop();
		}else{

			speed = pos.sub(box.getCenter());
            speed = speed.vectorNormalize().vectorXScalar(PLAYER_SPEED*dt);

			box.sumPoint(speed);
		}
	}


}

void Player::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
}

bool Player::isDead(){
	return false;
}

void Player::notifyCollision(GameObject& other){

}

bool Player::is(const std::string& type){
	return type == "Player";

}
