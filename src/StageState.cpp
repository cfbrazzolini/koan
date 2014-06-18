#include "StageState.h"

StageState::StageState() : bg("img/mapa.png")/*,tileSet(64,64,"img/tileset.png"),tileMap("map/tileMap.txt",&tileSet)*/,music("audio/tituloPrincipal.mp3") {
    
    float x,y;
    int id = 0;
    std::string file_name;
    std::ifstream file ("map/stoneMap.txt");
    std::string str;
    Stone* stone;
    Dice& dice = Dice::getInstance();

    music.play(-1);
    StateData::turn = 0;
    
    if(file.is_open()){
        while(getline(file,str,',')){
            x = strtol(str.c_str(),nullptr,10);
            getline(file,str,'\t');
            y = strtol(str.c_str(),nullptr,10);
            getline(file,str);

            stone = new Stone(x,y,"img/pedras/" + str + ".png","img/pedras/" + str + "destacada.png",id++);
            stoneArray.emplace_back(stone);
            objectArray.emplace_back(stone);
        }
    }

    objectArray.emplace_back(new Player(0,0,stoneArray));
    objectArray.emplace_back(new Player(1,15,stoneArray));

    objectArray.emplace_back(&dice);
    file.close();

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

   /* for(i=0;i<tileMap.getDepth();i++){
         tileMap.renderLayer(i,(i+1)*Camera::pos.getX(),(i+1)*Camera::pos.getY());
    }
*/
    renderArray();
}

/*
void StageState::addObject(float mouseX,float mouseY){
    

}
*/
