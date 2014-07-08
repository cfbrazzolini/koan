#ifndef STATEDATA_H
#define STATEDATA_H

#include <string>
#include <vector>

#include "Item.h"

class StateData
{
public:

	bool playerVictory;
    static int turn;
    static std::vector<int> playerHp;
    static std::vector<std::string> itemArray;
    static bool correctAnswer;
    

};

#endif // STATEDATA_H
