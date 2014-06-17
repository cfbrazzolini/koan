#include "Player.h"

Player::Player(int id,int pos,std::vector<Stone*> stoneArray) : spFrente("img/Movimento/frente.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
                                                        spDireita("img/Movimento/direita.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
                                                        spEsquerda("img/Movimento/esquerda.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
                                                        spCostas("img/Movimento/costas.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
                                                        stoneArray(stoneArray),
                                                        currentPos(pos),
                                                        id(id)
{
    sp = &spFrente;
    sp->setScale(0.2);
	rotation = 0;
	flip = SDL_FLIP_NONE;

	box.setX(stoneArray[pos]->box.getCenter().getX() - sp->getWidth()/2);
	box.setY(stoneArray[pos]->box.getCenter().getY()- sp->getHeight());
    box.setW(sp->getWidth());
    box.setH(sp->getHeight());
}


void Player::update(float dt){

	auto& input = InputManager::getInstance();
	float angle;
	Point speed,pos;
	Point click;
	int i,posId;
    int distance;
	int targetId = -1;
    bool direction,done=false,alignment=false;
	TARGET_T target;

    if(StateData::turn == id){

        if (input.mousePress(SDL_BUTTON_RIGHT)){
            click.setX((float)input.getMouseX() + Camera::pos.getX());
            click.setY((float)input.getMouseY() + Camera::pos.getY());

            for(i=0;i<stoneArray.size();i++){
            	if(stoneArray[i]->box.hasPoint(click)){
                    targetId = stoneArray[i]->getId();
            		break;
            	}
            }


            if(targetId != -1){
                distance =  std::min(abs(targetId - currentPos),(int)stoneArray.size() - abs(targetId - currentPos));
                
                direction = (targetId == (currentPos + distance) % stoneArray.size());/* true = sentido horario;false = sentido anti-horario */

            	if(direction){
                    posId = currentPos;
                    for(i=0;i<distance;i++){
                        
                        posId = (posId + 1) % stoneArray.size();

            			target.pos.setX(stoneArray[posId]->box.getCenter().getX() + Camera::pos.getX());
                    	target.pos.setY(stoneArray[posId]->box.getCenter().getY() + Camera::pos.getY() - sp->getHeight()/2);
                    	target.id = posId;
                    	taskQueue.push(target);
            		}
            	}else{
                    if(currentPos > targetId){
                        for(i=currentPos-1;i>=targetId;i--){
                            target.pos.setX(stoneArray[i]->box.getCenter().getX() + Camera::pos.getX());
                            target.pos.setY(stoneArray[i]->box.getCenter().getY() + Camera::pos.getY() - sp->getHeight()/2);
                            target.id = i;
                            taskQueue.push(target);
                        }
                    }else{
                        i = currentPos-1;
                        while(!done){
                            if(i<0){
                            	i += stoneArray.size();
                            }
                            target.pos.setX(stoneArray[i]->box.getCenter().getX() + Camera::pos.getX());
                            target.pos.setY(stoneArray[i]->box.getCenter().getY() + Camera::pos.getY() - sp->getHeight()/2);
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

              if(!alignment){
                     angle = CustomMath::radToDeg(box.getCenter().computeInclination(taskQueue.front().pos));

                    if(angle<-45 && angle>=-135){
                        sp = &spCostas;
                    }
                    else if(angle>=-45 && angle<45){
                        sp = &spDireita;
                    }
                    else if(angle>=45 && angle<135){
                        sp = &spFrente;
                    }
                    else if(angle>=135 || angle<-135){
                        sp = &spEsquerda;
                    }
                    sp->setScale(0.2);

                    alignment = true;
                }

    		if(box.getCenter().computeDistance(target.pos) < 5){
    			taskQueue.pop();
                alignment = false;
                currentPos = target.id;

                sp->restartTimer();
                sp->setFrame(0);
                sp->update(0);

                if(!taskQueue.empty()){
                    angle = CustomMath::radToDeg(box.getCenter().computeInclination(taskQueue.front().pos));

                    if(angle<-45 && angle>=-135){
                        sp = &spCostas;
                    }
                    else if(angle>=-45 && angle<45){
                        sp = &spDireita;
                    }
                    else if(angle>=45 && angle<135){
                        sp = &spFrente;
                    }
                    else if(angle>=135 || angle<-135){
                        sp = &spEsquerda;
                    }
                    sp->setScale(0.2);
                }else{
                    /************ Troca turno  ************/
                    StateData::turn =  (StateData::turn + 1) % 2;
                }
    		}else{
    		  
                sp->update(dt);

    			speed = target.pos.sub(box.getCenter());
                speed = speed.vectorNormalize().vectorXScalar(PLAYER_SPEED*dt);

    			box.sumPoint(speed);
    		}
    	}

    }
}

void Player::render(){
	sp->render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation,flip);
}

bool Player::isDead(){
	return false;
}

void Player::notifyCollision(GameObject& other){

}

bool Player::is(const std::string& type){
	return type == "Player";

}
