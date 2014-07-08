#include "StateData.h"

int StateData::turn = 0;
std::vector<int> StateData::playerHp;
std::vector<std::string> StateData::itemArray;

bool StateData::correctAnswer = false;
int StateData::itemRandom = -1;