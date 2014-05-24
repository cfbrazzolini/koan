#include "State.h"

State::State() : hasRequestedDelete(false),hasRequestedQuit(false)
{
}

State::~State(){
	
}

void State::addObject(GameObject* ptr){
    objectArray.emplace_back(ptr);
}

bool State::requestedDelete(){
	return hasRequestedDelete;
}

bool State::requestedQuit(){
	return hasRequestedQuit;
}

void State::updateArray(float dt){

	int i;
	
	for(i=0;i<objectArray.size();i++){
    	objectArray[i]->update(dt);
    }
}


void State::renderArray(){

	int i;

    for(i=0;i<objectArray.size();i++){
        objectArray[i]->render();
    }
}
