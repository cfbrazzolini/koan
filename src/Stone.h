#ifndef STONE_H
#define STONE_H

#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Camera.h"
#include "GameObject.h"
#include "Path.h"
#include "Sprite.h"

class Stone : public GameObject
{
public:
    Stone(float,float,int,std::vector<int>*,const std::string&);
    void update(float);
    void render();
    bool isDead();
    void notifyCollision(GameObject&);
    bool is(const std::string&);
    void selecionar();
    int getId();
    std::vector<int>* getLinks();
    void findPaths(int,std::unordered_map<int,Stone*>&);
    void findTargets(int,int,int,int,std::unordered_map<int,Stone*>&,std::string = "");
    void printPaths();
    std::vector<Path*> getPaths(int);
private:
    Sprite* sp;
	Sprite spNormal;
	Sprite spDestacada;
    enum StoneState {NORMAL,DESTACADA};
    StoneState stoneState;
	int id;
    std::vector<int> links;
    std::vector<Path*> pathVector;
};

#endif // STONE_H
