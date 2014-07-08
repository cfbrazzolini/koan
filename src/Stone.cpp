#include "Stone.h"

Stone::Stone(float x,float y,int id,std::vector<int>* _links,const std::string& fileName) : 	spNormal("img/pedras/"+fileName+".png"),
																								spDestacada("img/pedras/"+fileName+"destacada.png"),
                                                                                        		sp(&spNormal),
                                                                                        		stoneState(NORMAL),
																								id(id),
                                                                                                trap(nullptr)
{

	rotation = 0;
	spDestacada.setScale(0.09);
	spNormal.setScale(0.09);
	box.setX(x - sp->getWidth()/2);
	box.setY(y - sp->getHeight()/2);
	box.setW(sp->getWidth());
	box.setH(sp->getHeight());

	for(int i=0;i<_links->size();i++){
        links.emplace_back(_links->at(i));
	}
}


void Stone::update(float dt){

}

void Stone::render(){
    sp->render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

bool Stone::isDead(){
    return false;
}

void Stone::notifyCollision(GameObject& other){

}

bool Stone::is(const std::string& type){
	return type == "Stone";
}

void Stone::selecionar(){
    if(stoneState == NORMAL){
		sp = &spDestacada;
        stoneState = DESTACADA;
	}else{
		sp = &spNormal;
        stoneState = NORMAL;
	}
}



int Stone::getId(){
	return id;
}

std::vector<int>* Stone::getLinks(){
	return &links;
}

void Stone::findPaths(int range,std::unordered_map<int,Stone*>& nodeMap){

	int i;

	for(i=1;i<=range;i++){
        findTargets(id,id,i,i,nodeMap);
	}

}



void Stone::findTargets(int pos,int origin,int movesLeft,int range,std::unordered_map<int,Stone*>& nodeMap,std::string path){
    
    if(movesLeft <= 0){
        //std::cout << path << std::to_string(pos) << std::endl;
        pathVector.emplace_back(new Path(pos,range,path + std::to_string(pos)));
        return;
    }

    movesLeft--;

    int size = nodeMap[pos]->getLinks()->size();

    for(int i=0;i < size &&  nodeMap[pos]->getLinks()->at(i) != 0;i++){

        int link = nodeMap[pos]->getLinks()->at(i);

        if(link != origin){
            findTargets(link,pos,movesLeft,range,nodeMap,path + std::to_string(pos) + "-");
        }

    }

}

void Stone::printPaths(){
    int i;

    printf("\n\nStone %d\n",id);

    for(i=0;i< pathVector.size();i++){
        printf("Target: %d\nDistance: %d\nPath: %s\n",pathVector[i]->getTarget(),pathVector[i]->getDistance(),pathVector[i]->getPath().c_str());
    }
}

std::vector<Path*> Stone::getPaths(int distance){

    int i;
    std::vector<Path*> validPaths;

    for(i=0;i<pathVector.size();i++){
        if(pathVector[i]->getDistance() == distance){
            validPaths.emplace_back(pathVector[i]);
        }
    }

    return validPaths;
}


void Stone::setTrap(Trap* trap){
    this->trap = trap;
}

void Stone::activateTrap(){
    trap->activate();
    trap = nullptr;
}

bool Stone::isTrapped(){
    return trap != nullptr;
}
