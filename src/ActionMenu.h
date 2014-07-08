#ifndef ACTIONMENU_H
#define ACTIONMENU_H

#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "ActionNode.h"
#include "Camera.h"
#include "Game.h"
#include "GameObject.h"
#include "Globals.h"
#include "InputManager.h"
#include "Sprite.h"

class ActionMenu : public GameObject
{
private:
	//enum PlayerState {STANDBY,MOVING,ATTACKING,STAND};
	std::map<int, ActionNode*> actionMap;
	Sprite* sp;
	ActionNode* currentNode;
	ActionNode* showingNode;
	ActionNode* root;
public:
	ActionMenu();
	std::vector<std::string> mountPath(std::string);
	void buildTree();
	void update(float);
	int update();
	void render();
	bool isDead();
	void notifyCollision(GameObject&);
	bool is(const std::string&);
};

#endif // ACTIONMENU_H
