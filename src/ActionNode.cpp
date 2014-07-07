#include "ActionNode.h"

ActionNode::ActionNode(std::string id,const std::string& file_name) : 	id(id),
																		count(0),
																		sp("img/actionmenu/"+file_name)
{
    sp.setScale(1/4);
}

void ActionNode::addChild(ActionNode* child){
	children[child->id] = child;
}

ActionNode* ActionNode::getChild(std::string id){
    auto node = children.find(id);
    if(node != children.end() ){
		return node->second;
	}else{
		return nullptr;
	}
}

std::map<std::string,ActionNode*>& ActionNode::getChildren(){
    return children;
}

std::string ActionNode::getId(){
	return id;
}

Sprite* ActionNode::getSprite(){
	return &sp;
}

ActionNode* ActionNode::getNextAction(){

	int i = 0;
	std::string path;
    ActionNode* action = nullptr;

	count = ((count + 1) % children.size()) + 1;

    for(auto it = children.begin();it != children.end();it++){
		i++;
        if(i==count){
            action = it->second;
        }
	}

    return action;
}

ActionNode* ActionNode::getPrevAction(){

	int i = 0;
	std::string path;
    ActionNode* action = nullptr;

	count--;

	if(count < 1){
		count += children.size();
	}

    for(auto it = children.begin();it != children.end();it++){
        i++;
        if(i==count){
            action = it->second;
        }
    }

    return action;
}

void ActionNode::resetCount(){
	count = 0;
}
