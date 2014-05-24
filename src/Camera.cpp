#include "Camera.h"


Point Camera::pos;
float Camera::speed = 200;
GameObject* Camera::focus = nullptr;

void Camera::follow(GameObject* newFocus){
	focus = newFocus;
}

void Camera::unfollow(){
	focus = nullptr;
}

void Camera::update(float dt){

	if(focus != nullptr){

		auto& game = Game::getInstance();

		pos.setX(focus->box.getCenter().getX() - game.getWindowWidth()/2);
		pos.setY(focus->box.getCenter().getY() - game.getWindowHeight()/2);

	}else{

		auto& input = InputManager::getInstance();
		Point direction;

		if(input.isKeyDown(UP_ARROW_KEY)){
			direction.setY(-1);
		}
		else if(input.isKeyDown(DOWN_ARROW_KEY)){
			direction.setY(1);
		}

		if(input.isKeyDown(RIGHT_ARROW_KEY)){
			direction.setX(1);
		}
		else if(input.isKeyDown(LEFT_ARROW_KEY)){
			direction.setX(-1);
		}

		if(direction.vectorMagnitude() > 0){
			direction = direction.vectorNormalize().vectorXScalar(speed);
			pos = pos.sum(direction.vectorXScalar(dt));
		}

	}
}

