#include "ActionMenu.h"

ActionMenu::ActionMenu(float x, float y) :
sp(nullptr),
root(nullptr),
currentNode(nullptr)
{

    buildTree();

    if(x==0){
        box.setX(0);
    }else{
        box.setX( x - sp->getWidth());
    }

    box.setY(y - sp->getHeight());
    rotation = 0;

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
    std::vector<std::string> path;
    ActionNode *node,*last_node;
    std::ifstream file ("map/actionMap.txt");
    int idNum,type;

    if(file.is_open()){
        while(getline(file,str)&& str!="#"){
            path = mountPath(str);

            last_node = nullptr;

            for(auto id : path){

                auto pos = actionMap.find(std::stoi(id));
                if(pos == actionMap.end()){
                    node = new ActionNode(std::stoi(id),-1,id);
                    actionMap[node->getId()] = node;
                    if(sp == nullptr){
                        sp = node->getSprite();
                        currentNode = node;
                        root = node;
                        showingNode = node;
                    }
                }else{
                    node = pos->second;
                }

                if(last_node != nullptr){
                    last_node->addChild(node);
                }
                last_node = node;    
            }
        }
        while(getline(file,str)){
              path = mountPath(str);
              idNum = std::stoi(path[0]);
              type = std::stoi(path[1]);

              actionMap[idNum]->setType(type);
        }
    }

    file.close();       
}

void ActionMenu::update(float dt){

}

int ActionMenu::update(){

    auto& input = InputManager::getInstance();
    int result = Globals::START;
    bool found = false;

    if(showingNode->getId() != 2000){
        if(input.keyPress(SDLK_DOWN)){
            showingNode = currentNode->getNextAction();
        }
        else if(input.keyPress(SDLK_UP)){
            showingNode = currentNode->getPrevAction();
        }
        else if(input.keyPress(ENTER_KEY)){

            result = showingNode->getType();

            for(auto it = showingNode->getChildren().begin();it != showingNode->getChildren().end();it++){
                if(it->second->getType() == 0){
                    currentNode = it->second;
                    showingNode = it->second;
                    found = true;
                    break;
                }
            }
            if(!found){
                 for(auto it = showingNode->getChildren().begin();it != showingNode->getChildren().end();it++){
                    if(it->second->getType() == 4){
                        currentNode = it->second;
                        showingNode = it->second;
                        break;
                    }
                }
            }

        }
    }else{
        if(input.keyPress(ENTER_KEY)){
            result = Globals::FINISH;
        }
    }

    if(result == Globals::FINISH){
        currentNode = root;
        showingNode = root;
    }

    sp = showingNode->getSprite();
    return result;
}

void ActionMenu::render(){
    sp->render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

bool ActionMenu::isDead(){
    return false;
}

void ActionMenu::notifyCollision(GameObject& other){

}

bool ActionMenu::is(const std::string& type){
    return false;
}
