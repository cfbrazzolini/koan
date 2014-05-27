#include "Player.h"

#include <iostream>

Player::Player(int id,std::vector<Stone*> stoneArray) : sp("img/mestre.png"),stoneArray(stoneArray),currentId(id)
{
	sp.setScale(0.02);
	rotation = 0;
	flip = SDL_FLIP_NONE;

	box.setX(stoneArray[id]->box.getCenter().getX() - sp.getWidth()/2);
	box.setY(stoneArray[id]->box.getCenter().getY()- sp.getHeight());
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());
}


void Player::update(float dt){

	auto& input = InputManager::getInstance();
	float angle;
	Point speed,pos;
	Point click;
	int i;
	int targetId = -1;
    bool direction,done=false;
	TARGET_T target;

    if (input.mousePress(SDL_BUTTON_RIGHT)){
        click.setX((float)input.getMouseX() + Camera::pos.getX());
        click.setY((float)input.getMouseY() + Camera::pos.getY());

        for(i=0;i<stoneArray.size();i++){
        	if(stoneArray[i]->box.hasPoint(click)){
               /* click.setX(stoneArray[i]->box.getCenter().getX() + Camera::pos.getX());
                click.setY(stoneArray[i]->box.getCenter().getY() + Camera::pos.getY() - sp.getHeight()/2);*/

                targetId = stoneArray[i]->getId();
        		  //taskQueue.push(click);
        		break;
        	}
        }


        if(targetId != -1){
            direction = (targetId - currentId) <= stoneArray.size()/2;/* true = sentido horario;false = sentido anti-horario */

        	if(direction){
                for(i=currentId+1;i<=targetId;i++){
        			target.pos.setX(stoneArray[i]->box.getCenter().getX() + Camera::pos.getX());
                	target.pos.setY(stoneArray[i]->box.getCenter().getY() + Camera::pos.getY() - sp.getHeight()/2);
                	target.id = i;
                	taskQueue.push(target);
        		}
        	}else{
                if(currentId > targetId){
                    for(i=currentId-1;i>=targetId;i--){
                        target.pos.setX(stoneArray[i]->box.getCenter().getX() + Camera::pos.getX());
                        target.pos.setY(stoneArray[i]->box.getCenter().getY() + Camera::pos.getY() - sp.getHeight()/2);
                        target.id = i;
                        taskQueue.push(target);
                    }
                }else{
                    i = currentId-1;
                    while(!done){
                        if(i<0){
                        	i += stoneArray.size();
                        }
                        target.pos.setX(stoneArray[i]->box.getCenter().getX() + Camera::pos.getX());
                        target.pos.setY(stoneArray[i]->box.getCenter().getY() + Camera::pos.getY() - sp.getHeight()/2);
                        target.id = i;
                        taskQueue.push(target);
                        if(i == targetId){
                            done = true;
                        }else{
                            i--;
                        }
                    }
                }
        	}

        }
	  
	}

	if(!taskQueue.empty()){
		target = taskQueue.front();

		if(box.getCenter().computeDistance(target.pos) < 5){
			taskQueue.pop();
			currentId = target.id;
		}else{

			
			//rotation = CustomMath::radToDeg(box.getCenter().computeInclination(pos));


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

			speed = target.pos.sub(box.getCenter());
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
