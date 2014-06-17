#include "StillAnimation.h"

StillAnimation::StillAnimation(float x,float y,float rotation,Sprite sp,float timeLimit, bool ends, Sound sound) : 	sp(sp),
																													timeLimit(timeLimit),
																													endTimer(),
																													oneTimeOnly(ends),
																													sound(sound)
{

	this->rotation = rotation;
	box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

	sound.play(0);
}

StillAnimation::~StillAnimation(){

}


void StillAnimation::update(float dt){
	endTimer.update(dt);
	sp.update(dt);
}

void StillAnimation::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

bool StillAnimation::isDead(){

	if(oneTimeOnly){
		return endTimer.getTime() >= timeLimit;
	}else{
		return false;
	}
}

void StillAnimation::notifyCollision(GameObject& other){


}

bool StillAnimation::is(const std::string& type){
	return type == "StillAnimation";
}