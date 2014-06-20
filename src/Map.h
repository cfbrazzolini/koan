#ifndef MAP_H
#define MAP_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>


#include "Stone.h"


class Map
{
public:
	Map();
    static Map& getInstance();
    static std::unordered_map<int,Stone*> nodeMap;
};

#endif // MAP_H
