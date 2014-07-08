#include "ActionMenu.h"

ActionMenu::ActionMenu(float x,float y) : currentNode(nullptr),nextAction(nullptr),done(false)
{
	buildTree();
	printTree();

    box.setX(x - actions["1"]->getSprite()->getWidth()/2);
    box.setY(y - actions["1"]->getSprite()->getHeight()/2);

}

void ActionMenu::printTree(ActionNode* node){

	if(node == nullptr){
		node = actions["1"];
        printf("%s\n\n",node->getId().c_str());
    }
    

    for(auto i = 0;i < node->getId().size();i++){
		printf("-");
	}
    printf(">%s\n",node->getId().c_str());


    auto children  = node->getChildren();
	for(auto it = children.begin();it != children.end();it++){
		printTree(it->second);
	}

}

std::vector<std::string> ActionMenu::mountPath(std::string str){
    std::vector<std::string> path;
    std::istringstream iss(str);
    char delim = '-';

    for (std::string token; std::getline(iss, token, delim); )
    {
        path.push_back(std::move(token));
    }

    return path;
}


void ActionMenu::buildTree(){

    std::string file_name,str;
    std::ifstream file ("map/actionMap.txt");
    ActionNode* node;
    ActionNode* lastNode;

    if(file.is_open()){
    	while(getline(file,str)){
    		lastNode = nullptr;
    		node = nullptr;

            //printf("Line: %s\n\n",str.c_str());

            auto path = mountPath(str);
    		for(auto id : path){
                //printf("%s\n",id.c_str());
                auto pos = actions.find(id);
                if(pos == actions.end()){

                    node = new ActionNode(id,id+".PNG");
    				actions[id] = node;
                    //printf("%s\n",actions[id]->getId().c_str());
                    if(currentNode == nullptr){
                        currentNode = node;
                    }
    			}else{
                    node = pos->second;
    			}

    			if(lastNode != nullptr){
    				lastNode->addChild(node);
    			}
                lastNode = node;
    		}
            //printf("\n\n");

        }
    }
    file.close();
    //printf("Root id: %s\n\n",actions.begin()->second->getId().c_str());
}



int ActionMenu::update(bool moved,bool attacked){
    auto& input = InputManager::getInstance();
    PlayerState result = STANDBY;

    if(moved && !attacked && !done){
        currentNode = actions["120"];
        done = true;
    }
    else if(attacked && !moved && !done){
        currentNode = actions["110"];
        done = true;
    }
    else if(!moved && !attacked && !done){
        currentNode = actions["1"];
        done = true;
    }

    if(nextAction == nullptr){
        nextAction = currentNode;
    }

    if(input.keyPress(SDLK_UP)){
        nextAction = currentNode->getNextAction();
    }
    else if(input.keyPress(SDLK_DOWN)){
        nextAction = currentNode->getPrevAction();
    }
    else if(input.keyPress(ENTER_KEY)){

        if(currentNode->getId().back() != '0'){
            if(currentNode->getId() == "11" || currentNode->getId() == "121" || currentNode->getId() == "131"){
            result = ATTACKING;
            }
            else if(currentNode->getId() == "111" || currentNode->getId() == "12"){
                result = MOVING;
            }
            else if(currentNode->getId() == "112" || currentNode->getId() == "13"){
                result = STAND;
            }


            if(currentNode->getId().size() == 3){
                currentNode = actions["2"];
            }else{
                currentNode = actions[nextAction->getId()+"0"];
            }
            nextAction = nullptr;
        }
    }

    return result;
}

void ActionMenu::update(float dt){
    
}

void ActionMenu::render(){
    nextAction->getSprite()->render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

bool ActionMenu::isDead(){

}

void ActionMenu::notifyCollision(GameObject& other){

}

bool ActionMenu::is(const std::string& type){
	return type == "ActionMenu";
}
