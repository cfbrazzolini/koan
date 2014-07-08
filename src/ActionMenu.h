#ifndef ACTIONMENU_H
#define ACTIONMENU_H

#include <cstdio>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "ActionNode.h"
#include "Camera.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Sprite.h"

class ActionMenu : public GameObject
{
private:
	enum PlayerState {STANDBY,MOVING,ATTACKING,STAND};
	ActionNode* currentNode;
	ActionNode* nextAction;
	std::map<std::string,ActionNode*> actions;
	bool done;
public:
    ActionMenu(float=Game::getInstance().getWindowWidth()/2,float=Game::getInstance().getWindowHeight()/2);
    std::vector<std::string> mountPath(std::string);
    void buildTree();
    int update(bool=false,bool=false);
    void update(float);
	void render();
	bool isDead();
	void notifyCollision(GameObject&);
	bool is(const std::string&);
    void printTree(ActionNode* = nullptr);

};

#endif // ACTIONMENU_H
