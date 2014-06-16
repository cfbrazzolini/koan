// #include "initialState.h"

// initialState::initialState() : bg("img/title.jpg"),
// 							   instruction("font/Call me maybe.ttf",34,Text::TEXT_SOLID,"Press space to try again or ESC to exit",SDL_Color(),0,0)
// {
// }

// // initialState::~initialState(){
// // }

// void initialState::update(){
// 	input();
// }

// void initialState::render(){
// 	bg.render(0,0);
// }

// void initialState::input() {
// 	auto& input = InputManager::getInstance();

//     if( input.shouldQuit()){
//         hasRequestedQuit = true;
//     }

//     if(input.keyPress(ESCAPE_KEY)){
//         hasRequestedDelete = true;
//     }

//     if(input.keyPress(SPACE_KEY)){
//     	hasRequestedDelete = true;
//         Game::getInstance().push(new StageState());
//     }   
// }

