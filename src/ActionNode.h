#ifndef ACTIONNODE_H
#define ACTIONNODE_H

#include <string>
#include <map>

#include "Game.h"
#include "Sprite.h"

class ActionNode
{
public:
    ActionNode(std::string,const std::string&);
    void addChild(ActionNode* child);
    ActionNode* getChild(std::string);
    std::map<std::string,ActionNode*>& getChildren();
    std::string getId();
    ActionNode* getNextAction();
    ActionNode* getPrevAction();
    Sprite* getSprite();
    void resetCount();
private:
	Sprite sp;
	int count;
	std::string id;
	std::map<std::string,ActionNode*> children;

};

#endif // ACTIONNODE_H
