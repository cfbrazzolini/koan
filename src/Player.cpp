#include "Player.h"

#include <iostream>

Player::Player(int id,int pos,std::vector<Stone*> stoneArray) : spFrente("img/Movimento/vermelhoFrente.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
                                                        spDireita("img/Movimento/vermelhoDireita.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
                                                        spEsquerda("img/Movimento/vermelhoEsquerda.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
                                                        spCostas("img/Movimento/vermelhoCostas.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
                                                        stoneArray(stoneArray),
                                                        currentPos(pos),
                                                        //dice(750,550),
                                                        moved(false),
                                                        attacked(false),
                                                        jogouDado(false),
                                                        playerState(STANDBY),
                                                        movementsRemaining(0),
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
    auto& dice = Dice::getInstance();
    float angle;
    Point speed,pos;
    Point click;
    int i,j,posId;
    int distance;
    int targetId = -1;
    bool direction,done=false,alignment=false;
    TARGET_T target;


    if(StateData::turn == id){

        switch(playerState){

            case STANDBY:

                if(moved && attacked){
                    /****** Passa a vez ******/
                    moved = false;
                    attacked = false;
                    jogouDado = false;
                    StateData::turn = (StateData::turn + 1) % 2;
                }
                else if(moved){
                    /****** Jogador já se moveu mas nao attacked ******/
                    playerState = ATTACKING;
                }
                else if(attacked){
                    /****** Jogador já attacked mas nao se moveu ******/
                    playerState = MOVING;
                }
                else{
                    /****** Comeco do turno desse jogador ******/
                    //chooseAction();
                    playerState = MOVING;
                }
                break;

            case MOVING:

                if(!jogouDado){

                    /*< Inicio do movimento */

                    /*< Rola o dado */
                    dice.setValue();
                    //dice.update(dt);
                    movementsRemaining = dice.getValue();
                    /* Rola o dado >*/

                    /*< Calcula casas alcancaveis e muda suas cores */

                    validStones.emplace_back(currentPos);
                    validStones.emplace_back((currentPos + movementsRemaining) % stoneArray.size());


                    posId = (currentPos - movementsRemaining);

                    if(posId < 0){
                        posId += stoneArray.size();
                    }

                    validStones.emplace_back(posId);

                    for(i=0;i<validStones.size();i++){
                        stoneArray[validStones[i]]->selecionar();
                    }
                    
                    /* Calcula casas alcancaveis e muda suas cores >*/

                    
                    jogouDado = true;
                    /* Inicio do movimento >*/
                }

                /*< Pega click do jogador em uma casa válida e enfileira as casas necessaria, entao retorna casas para cores normais */

                if (taskQueue.empty() && input.mousePress(SDL_BUTTON_RIGHT)){

                    click.setX((float)input.getMouseX() + Camera::pos.getX());
                    click.setY((float)input.getMouseY() + Camera::pos.getY());

                    for(i=0;i<validStones.size();i++){
                        if(stoneArray[validStones[i]]->box.hasPoint(click)){
                            targetId = validStones[i];
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



                /* Pega click do jogador em uma casa válida e enfileira as casas necessaria >*/



                if(!taskQueue.empty()){
                    
                    /*< Movimentacao */

                    for(j=0;j<validStones.size();j++){
                        stoneArray[validStones[j]]->selecionar();
                    }

                    validStones.clear();

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

                        /*< Chegou em uma casa */

                        taskQueue.pop();
                        alignment = false;
                        currentPos = target.id;

                        sp->restartTimer();
                        sp->setFrame(0);
                        sp->update(0);

                        if(!taskQueue.empty()){

                            /*< Nao e a ultima casa */

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

                            /* Nao e a ultima casa >*/

                        }else{
                            /************< Troca turno  ************/
                            moved = true;
                            jogouDado = false;
                            playerState = STANDBY;
                             /************ Troca turno  >************/
                        }

                        /* Chegou em uma casa >*/
                    }else{
                        /*< Em movimento entre casas */
                      
                        sp->update(dt);

                        speed = target.pos.sub(box.getCenter());
                        speed = speed.vectorNormalize().vectorXScalar(PLAYER_SPEED*dt);

                        box.sumPoint(speed);
                         /* Em movimento entre casas >*/
                    }

                    /* Movimentacao >*/
                }

                break;
            case ATTACKING:

                std::cout << "Ataquei!" << std::endl;
                attacked = true;
                playerState = STANDBY;


                break;
        }

    }
}

void Player::render(){
    sp->render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation,flip);
    //Dice::getInstance().render();
}

bool Player::isDead(){
    return false;
}

void Player::notifyCollision(GameObject& other){

}

bool Player::is(const std::string& type){
    return type == "Player";

}
