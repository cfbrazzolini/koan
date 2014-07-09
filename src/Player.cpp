#include "Player.h"

Player::Player(int id,int pos,std::unordered_map<int,Stone*> stoneArray,const std::string& color) : 
    spFrente("img/movimento/"+ color +"Frente.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
    spDireita("img/movimento/"+ color +"Direita.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
    spEsquerda("img/movimento/"+ color +"Esquerda.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
    spCostas("img/movimento/"+ color +"Costas.png",PLAYER_FRAME_COUNT,PLAYER_FRAME_TIME),
    stoneArray(stoneArray),
    currentPos(pos),
    moved(false),
    stood(false),
    attacked(false),
    jogouDado(false),
    playerState(STANDBY),
    movementsRemaining(0),
    hp(PLAYER_HP),
    id(id),
    color(color),
    actionMenu(Game::getInstance().getWindowWidth()*id,Game::getInstance().getWindowHeight())
{
    sp = &spFrente;
    sp->setScale(0.2);
    rotation = 0;
    flip = SDL_FLIP_NONE;

    box.setX(stoneArray[pos]->box.getCenter().getX() - sp->getWidth()/2);
    box.setY(stoneArray[pos]->box.getCenter().getY()- sp->getHeight());
    box.setW(sp->getWidth());
    box.setH(sp->getHeight());

    if(true){
        
        itemArray.emplace_back(new Sword());
        itemArray.emplace_back(new Bow());
        itemArray.emplace_back(new Shuriken());
        
    }

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
    int action;
    bool direction,done=false,alignment=false;
    TARGET_T target;
    std::vector<Path*> paths;
    std::string pathVector,str;
    std::size_t found,last_found;

    showActionMenu = false;


    if(StateData::turn == id){

        switch(playerState){

            case STANDBY:
                action = actionMenu.update();

                showActionMenu = false;

                switch(action){
                    case Globals::ATTACK :
                        playerState = ATTACKING;
                        break;
                    
                    case Globals::MOVE :
                        playerState = MOVING;
                        break;

                    case Globals::STAND:
                        playerState = STAND;
                        break;

                    case Globals::FINISH:
                        jogouDado = false;
                        StateData::turn = (StateData::turn + 1) % 2;
                        playerState = STANDBY;
                        break;
                    default:
                        playerState = STANDBY;
                        showActionMenu = true;
                        break;
                }

                break;

            case MOVING:

                if(!jogouDado){

                    /*< Inicio do movimento */

                    /*< Rola o dado */
                    dice.setValue();
                    /* Rola o dado >*/

                    /*< Calcula casas alcancaveis e muda suas cores */


                    paths = stoneArray[currentPos]->getPaths(dice.getValue());

                    validStones.clear();
                    validStones.emplace_back(currentPos);
                    for(i=0;i<paths.size();i++){
                         validStones.emplace_back(paths[i]->getTarget());
                    }


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

                        paths = stoneArray[currentPos]->getPaths(dice.getValue());

                         for(i=0;i<paths.size();i++){
                             if(paths[i]->getTarget() == targetId){
                                pathVector = paths[i]->getPath();
                                break;
                             }
                        }


                        last_found = 0;
                        while((last_found != std::string::npos) &&  (found = pathVector.find("-",last_found+1))){
                            posId = abs(strtol(pathVector.substr(last_found,found-last_found).c_str(),nullptr,10));
                            
                            last_found = found;

                            target.pos.setX(stoneArray[posId]->box.getCenter().getX() + Camera::pos.getX());
                            target.pos.setY(stoneArray[posId]->box.getCenter().getY() + Camera::pos.getY() - sp->getHeight()/2);
                            target.id = posId;
                            taskQueue.push(target);
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
                            Game::getInstance().push(new question());
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
            case STAND:
                    /************< Troca turno  ************/
                    stood = true;
                    jogouDado = false;
                    playerState = STANDBY;
                    Game::getInstance().push(new question());
                     /************ Troca turno  >************/
                break;
            case ATTACKING:

                /*std::cout << "Ataquei!" << std::endl;
                attacked = true;
                playerState = STANDBY;*/

                if(input.mousePress(SDL_BUTTON_LEFT)){
                    click.setX((float)input.getMouseX() + Camera::pos.getX());
                    click.setY((float)input.getMouseY() + Camera::pos.getY());
                    if(box.hasPoint(click)){
                        StateData::playerHp[(id+1)%2] = StateData::playerHp[(id+1)%2]--;
                        attacked = true;
                        playerState = STANDBY;
                    }
                }
                break;
        }
    }else{
         StateData::playerHp[id] = hp;
    }

    for(i=0;i<itemArray.size();i++){
        itemArray[i]->update(dt);
    }

    for(i=0;i<itemArray.size();i++){
            if(itemArray[i]->isDead()){
                itemArray.erase(itemArray.begin()+i);
            }
        }

   
}

void Player::render(){
    sp->render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation,flip);
    //Dice::getInstance().render();
    if(showActionMenu){
        actionMenu.render();
    }
}

bool Player::isDead(){
    return hp <= 0;
}

void Player::notifyCollision(GameObject& other){

}

bool Player::is(const std::string& type){
    return type == "Player";

}

int Player::getId(){
    return id;
}

int Player::getHp(){
    return hp;
}

std::vector<std::unique_ptr<Item>>* Player::getItens(){
    return &itemArray;
}

std::string& Player::getColor(){
    return color;
}
