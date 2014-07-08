#include "StageState.h"

// #include "ActionMenu.h"

StageState::StageState() : bg("img/cenario/mapanovo2.png"),music("audio/tituloPrincipal.mp3"),map(Map::getInstance()) {
    
    float x,y;
    int id = 0;
    std::string file_name;
    std::ifstream file ("map/stoneMap.txt");
    std::string str;
    Dice& dice = Dice::getInstance();
    Player* player;



    //music.play(-1);
    StateData::turn = 0;

    for(auto it=map.nodeMap.begin();it != map.nodeMap.end();++it){
            stoneArray.emplace(it->first,it->second);
            objectArray.emplace_back(it->second);
    }

    player = new Player(0,1,stoneArray,"vermelho");

    objectArray.emplace_back(player);
    StateData::playerHp.emplace_back(20);
    objectArray.emplace_back(new Hud(0,0,0,player));

    player = new Player(1,15,stoneArray,"laranja");
    
    objectArray.emplace_back(player);
    StateData::playerHp.emplace_back(20);
    objectArray.emplace_back(new Hud(0,0,1,player));

    objectArray.emplace_back(&dice);
    file.close();

    StateData::itemArray.emplace_back("Sword");
    StateData::itemArray.emplace_back("Shuriken");
    StateData::itemArray.emplace_back("Trap");
    StateData::itemArray.emplace_back("Bow");
    StateData::itemArray.emplace_back("Helmet");



}

StageState::~StageState(){
    //Sprite::clear();
    //music.stop();
    //Music::clear();
    objectArray.clear();
}


void StageState::input() {
    
}

void StageState::update(float dt){

    int i,j;
    auto &input = InputManager::getInstance();
    int mouseX = InputManager::getInstance().getMouseX();
    int mouseY = InputManager::getInstance().getMouseY();
    //float dt = Game::getDeltaTime();

    if(!hasRequestedDelete){
        

        Camera::update(dt);

        for(i=0;i<StateData::playerHp.size();i++){
            if(StateData::playerHp[i] <= 0){
                StateData data;
                data.playerVictory = false;
                Game::getInstance().push(new EndState(data)); 
            }
        }


        
        if(input.shouldQuit()){
            hasRequestedQuit = true;
        }

        if(input.keyPress(ESCAPE_KEY)){
            hasRequestedDelete = true;

        }


        if (input.isKeyDown(X_KEY)) {
            objectArray.clear();
        }


        
        updateArray(dt);
        

        for(i = 0; i < objectArray.size(); i++) {
           for (j = i; j < objectArray.size(); j++)       {
                if(Collision::IsColliding(objectArray[i]->box,objectArray[j]->box,objectArray[i]->rotation,objectArray[j]->rotation)){
                    objectArray[i]->notifyCollision(*objectArray[j]);
                    objectArray[j]->notifyCollision(*objectArray[i]);
                }
           }
        }

        

        for(i=0;i<objectArray.size();i++){
            if(objectArray[i]->isDead()){
                objectArray.erase(objectArray.begin()+i);
            }
        }
    }
}

void StageState::render(){

    int i;


    bg.render(0,0);
    renderArray();
}
