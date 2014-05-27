#include "Player.h"

Player::Player(float x,float y) : sp("img/mestre.png")
{
	sp.setScale(0.05);
	rotation = 0;
	flip = SDL_FLIP_NONE;

	box.setX(x - sp.getWidth()/2);
	box.setY(y- sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());
}


void Player::update(float dt){

	auto& input = InputManager::getInstance();
	float angle;
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

			
			rotation = CustomMath::radToDeg(box.getCenter().computeInclination(pos));


			if(flip == SDL_FLIP_NONE && (rotation > 90 || rotation < -90)){
				flip = SDL_FLIP_VERTICAL;
			}
			else if(flip == SDL_FLIP_VERTICAL && (rotation < 90 && rotation > -90)){
				flip = SDL_FLIP_NONE;
			}



			/*if(rotation > 90){
				//rotation = rotation - 180;
			}
			else if(rotation < -90){
				//rotation = rotation + 180;
			}*/

			speed = pos.sub(box.getCenter());
            speed = speed.vectorNormalize().vectorXScalar(PLAYER_SPEED*dt);

			box.sumPoint(speed);
		}
	}


}

void Player::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation,flip);
}

bool Player::isDead(){
	return false;
}

void Player::notifyCollision(GameObject& other){

}

bool Player::is(const std::string& type){
	return type == "Player";

}
