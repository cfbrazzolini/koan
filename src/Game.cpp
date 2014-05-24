#include "Game.h"

Game* Game::instance = nullptr;

std::stack<std::unique_ptr<State>> Game::stateStack;


Game::Game(const std::string& title, int width, int height){

    frameStart = 0;
    storedState = nullptr;
    srand(time(NULL));
    
    if(instance != nullptr){
        throw "Erro! Ja foi criado instance, chame esse construtor somente 1 vez";
    }
    else
        instance = this;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)!=0){
        throw "erro ao inicializar a biblioteca SDL";
    }
    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)!=(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
        throw "erro ao carregar a biblioteca IMG_Init";
    }
    if((window = SDL_CreateWindow(title.c_str(), 100,100, width, height, 0)) == nullptr){
        throw "nao abriu janela!";
    }
    if((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == nullptr){
        throw "nao criou renderer";
    }

    if(Mix_Init(MIX_INIT_OGG) != (MIX_INIT_OGG)){
        throw "erro ao carregar biblioteca MIX_Init";
    }
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) != 0){
        throw "erro na Mix_OpenAudio";
    }

    if(TTF_Init() != 0){
         throw "erro na TTF_Init";
    }

}

Game::~Game(){
    IMG_Quit();
    TTF_Quit();
    Mix_CloseAudio();
    Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    instance = nullptr;
    storedState = nullptr;
}

SDL_Renderer* Game::getRenderer(){
     return renderer;
}

Game& Game::getInstance(){
    return *instance;
}

State& Game::getCurrentState(){
    return *(stateStack.top());
}

void Game::push(State* state){
    //stateStack.push(storedState);
    storedState = state;
}

void Game::run(){

    stateStack.emplace(storedState);
    storedState = nullptr;


    while(!stateStack.empty() && !stateStack.top()->requestedQuit()){
        calculateDeltaTime();
        InputManager::getInstance().update();

        if(storedState != nullptr){
            stateStack.emplace(storedState);
            storedState = nullptr;
        }

        while(stateStack.top()->requestedDelete()){
            
            stateStack.pop();

            if(storedState != nullptr){
                stateStack.emplace(storedState);
                storedState = nullptr;
            }

            if(stateStack.empty()){
                break;
            }
        }

        stateStack.top()->update(dt);
        stateStack.top()->render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }

}

void Game::calculateDeltaTime(){
    int ticks = SDL_GetTicks();
    dt = (float)(ticks - frameStart)/1000;
    frameStart = ticks;
}


int Game::getWindowWidth(){

    int w, h;

    SDL_GetWindowSize(window, &w, &h);
    return w;
}

int Game::getWindowHeight(){

    int w, h;
    
    SDL_GetWindowSize(window, &w, &h);
    return h;
}
