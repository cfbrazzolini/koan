#ifndef ACTIONNODE_H
#define ACTIONNODE_H

#include <map>
#include <string>

#include "Sprite.h"

class ActionNode
{
private:
    int id;
    Sprite sp;
    std::map<int, ActionNode*> children;
    int type;
    int currentAction;

public:
    ActionNode(int,int,const std::string&);
    int getId();
    int getType();
    void setType(int);
    Sprite* getSprite();
    std::map<int, ActionNode*>& getChildren();
    void addChild(ActionNode*);
    ActionNode* getNextAction();
    ActionNode* getPrevAction();
};

#endif // ACTIONNODE_H
