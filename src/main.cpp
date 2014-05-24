#include <cstdlib>
#include <iostream>

#include "Game.h"
#include "TileState.h"

using namespace std;

int main(int argc, char **argv){


    Game game("IDJ - Caina 09/0108094", 1024, 600);

    game.push(new TileState());
//    system("pwd");
    game.run();
    return 0;
}

