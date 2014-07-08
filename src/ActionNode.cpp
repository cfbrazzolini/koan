#include "ActionNode.h"

ActionNode::ActionNode(int id,int type,const std::string& file_name) :
id(id),
type(type),
sp("img/actionmenu/"+file_name+".png"),
currentAction(-1)
{
    sp.setScale(0.375);

}

int ActionNode::getId(){
	return id;
}

Sprite* ActionNode::getSprite(){
	return &sp;
}

std::map<int, ActionNode*>& ActionNode::getChildren(){
	return children;
}

void ActionNode::addChild(ActionNode* child){
	children[child->id] = child;
}

int ActionNode::getType(){
	return type;
}

void ActionNode::setType(int type){
	this->type = type;
}

ActionNode* ActionNode::getNextAction(){
	int i = 0;
	ActionNode* nextAction = nullptr;

	currentAction = (currentAction+1)%children.size();

	for(auto it = children.begin();it!=children.end();it++){
		if(i==currentAction){
			nextAction = it->second;
			break;
		}else{
			i++;
		}
	}

	return nextAction;
}

ActionNode* ActionNode::getPrevAction(){
	int i = 0;
	ActionNode* nextAction = nullptr;

	currentAction--;

	if(currentAction < 0){
		currentAction += children.size();
	}

	for(auto it = children.begin();it!=children.end();it++){
		if(i==currentAction){
			nextAction = it->second;
			break;
		}else{
			i++;
		}
	}

	return nextAction;
}