#include "question.h"

using namespace std;

question::question() :  bg("img/perguntas/mapaembacado.png"),
						mestre("img/perguntas/mestre.png"),
						balao("img/perguntas/balao.png"),
						pVerde("img/perguntas/pergaminhoverde.png"),
						pRoxo("img/perguntas/pergaminhoroxo.png"),
						pVermelho("img/perguntas/pergaminhovermelho.png"),
						pAmarelo("img/perguntas/pergaminhoamarelo.png"),
						pergunta("font/tomouseA.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						certa("font/tomouseA.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						errada1("font/tomouseA.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						errada2("font/tomouseA.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						errada3("font/tomouseA.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0)
{
	mestre.setScale(0.19);
    mestreBox.setX(Game::getInstance().getWindowWidth() - mestre.getWidth() - 460);
    mestreBox.setY(Game::getInstance().getWindowHeight() - mestre.getHeight() - 40);

	balaoBox.setX(Game::getInstance().getWindowWidth() - balao.getWidth() - 20);
    balaoBox.setY(Game::getInstance().getWindowHeight() - balao.getHeight() - 400);

    verdeBox.setX(Game::getInstance().getWindowWidth() - pVerde.getWidth() - 30);
    verdeBox.setY(Game::getInstance().getWindowHeight() - pVerde.getHeight() - 280);

    vermelhoBox.setX(Game::getInstance().getWindowWidth() - pVermelho.getWidth() - 30);
    vermelhoBox.setY(Game::getInstance().getWindowHeight() - pVermelho.getHeight() - 170);

    roxoBox.setX(Game::getInstance().getWindowWidth() - pRoxo.getWidth() - 30);
    roxoBox.setY(Game::getInstance().getWindowHeight() - pRoxo.getHeight() - 70);

    amareloBox.setX(Game::getInstance().getWindowWidth() - pAmarelo.getWidth() - 30);
    amareloBox.setY(Game::getInstance().getWindowHeight() - pAmarelo.getHeight() + 20);

	answer = VERDE;

    int opcao = (rand() % 3);
    int value = 0, index = 0;
	if(opcao == 0){
		// escolhe uma linha do arq grammar
		std::ifstream file ("img/grammar.txt");
		value = (rand() % 32);
    	index = value*5 + 1;cout << file << endl;
	    std::string strPergunta, strCorreta1, strErrada1, strErrada2, strErrada3;
	    if(file.is_open()){
	    	
	        // acha a linha
	        for(int i = 0; i < index; i++){
	    		getline(file,strPergunta,'\n');
	    	}
	    	getline(file,strCorreta1,'\n');
	    	getline(file,strErrada1,'\n');
	    	getline(file,strErrada2,'\n');
	  		getline(file,strErrada3,'\n');
	    
	        pergunta.setText(strPergunta);
			pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
	        certa.setText(strCorreta1);
			certa.setPos((verdeBox.getX() - Camera::pos.getX())/2,(verdeBox.getY() - Camera::pos.getY())/2 - 10,true,true);
	        errada1.setText(strErrada1);
			errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2,(vermelhoBox.getY() - Camera::pos.getY())/2 - 70,true,true);
	        errada2.setText(strErrada2);
			errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2,(roxoBox.getY() - Camera::pos.getY())/2 - 120,true,true);
	        errada3.setText(strErrada3);
			errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2,(amareloBox.getY() - Camera::pos.getY())/2 - 160,true,true);
	        
	        }else{
		        printf("Nao conseguiu abrir\n");
	    }
	    file.close();
	}
	if(opcao == 1){
		std::ifstream file ("img/expressoes.txt");
		value = (rand() % 29);
    	index = value*5 + 1;cout << file << endl;
    	std::string strPergunta, strCorreta1, strErrada1, strErrada2, strErrada3;
	    if(file.is_open()){
	    	
	        // acha a linha
	        for(int i = 0; i < index; i++){
	    		getline(file,strPergunta,'\n');
	    	}
	    	getline(file,strCorreta1,'\n');
	    	getline(file,strErrada1,'\n');
	    	getline(file,strErrada2,'\n');
	  		getline(file,strErrada3,'\n');
	    
	        pergunta.setText(strPergunta);
			pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
	        certa.setText(strCorreta1);
			certa.setPos((verdeBox.getX() - Camera::pos.getX())/2,(verdeBox.getY() - Camera::pos.getY())/2 - 10,true,true);
	        errada1.setText(strErrada1);
			errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2,(vermelhoBox.getY() - Camera::pos.getY())/2 - 70,true,true);
	        errada2.setText(strErrada2);
			errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2,(roxoBox.getY() - Camera::pos.getY())/2 - 120,true,true);
	        errada3.setText(strErrada3);
			errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2,(amareloBox.getY() - Camera::pos.getY())/2 - 160,true,true);
	        
	        }else{
		        printf("Nao conseguiu abrir\n");
	    }
	    file.close();
	}
	if(opcao == 2){
		std::ifstream file ("img/kanji.txt");
		value = (rand() % 202);
    	index = value*5 + 1;cout << file << endl;
    	std::string strPergunta, strCorreta1, strErrada1, strErrada2, strErrada3;
	    if(file.is_open()){
	    	
	        // acha a linha
	        for(int i = 0; i < index; i++){
	    		getline(file,strPergunta,'\n');
	    	}
	    	getline(file,strCorreta1,'\n');
	    	getline(file,strErrada1,'\n');
	    	getline(file,strErrada2,'\n');
	  		getline(file,strErrada3,'\n');
	    
	        pergunta.setText(strPergunta);
			pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
	        certa.setText(strCorreta1);
			certa.setPos((verdeBox.getX() - Camera::pos.getX())/2,(verdeBox.getY() - Camera::pos.getY())/2 - 10,true,true);
	        errada1.setText(strErrada1);
			errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2,(vermelhoBox.getY() - Camera::pos.getY())/2 - 70,true,true);
	        errada2.setText(strErrada2);
			errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2,(roxoBox.getY() - Camera::pos.getY())/2 - 120,true,true);
	        errada3.setText(strErrada3);
			errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2,(amareloBox.getY() - Camera::pos.getY())/2 - 160,true,true);
	        
	        }else{
		        printf("Nao conseguiu abrir\n");
	    }
	    file.close();
	}
}

void question::update(float){
	input();
}

void question::render(){
	bg.render(0,0);

    mestre.render(mestreBox.getX() - Camera::pos.getX(),mestreBox.getY() - Camera::pos.getY());
    balao.render(balaoBox.getX() - Camera::pos.getX(),balaoBox.getY() - Camera::pos.getY());
    pVerde.render(verdeBox.getX() - Camera::pos.getX(),verdeBox.getY() - Camera::pos.getY());
    pVermelho.render(vermelhoBox.getX() - Camera::pos.getX(),vermelhoBox.getY() - Camera::pos.getY());
    pRoxo.render(roxoBox.getX() - Camera::pos.getX(),roxoBox.getY() - Camera::pos.getY());
    pAmarelo.render(amareloBox.getX() - Camera::pos.getX(),amareloBox.getY() - Camera::pos.getY());

    pergunta.render(balaoBox.getX() - Camera::pos.getX(),balaoBox.getY() - Camera::pos.getY());
    certa.render(verdeBox.getX() - Camera::pos.getX(),verdeBox.getY() - Camera::pos.getY());
    errada1.render(vermelhoBox.getX() - Camera::pos.getX(),vermelhoBox.getY() - Camera::pos.getY());
    errada2.render(roxoBox.getX() - Camera::pos.getX(),roxoBox.getY() - Camera::pos.getY());
    errada3.render(amareloBox.getX() - Camera::pos.getX(),amareloBox.getY() - Camera::pos.getY());
}

void question::input(){

	auto& input = InputManager::getInstance();
    Point click;


    click.setX((float)input.getMouseX() + Camera::pos.getX());
    click.setY((float)input.getMouseY() + Camera::pos.getY());

    if(input.keyPress(ESCAPE_KEY) || input.shouldQuit()){
        hasRequestedQuit = true;
    }
    if(input.mousePress(SDL_BUTTON_LEFT) && verdeBox.hasPoint(click)){
    	printf("foi clicado\n");
        if(answer == VERDE){
        	StateData::correctAnswer = true;
        	cout <<StateData::correctAnswer<<endl;
        }
    }
    // if(input.mousePress(SDL_BUTTON_LEFT) && roxoBox.hasPoint(click)){
    //     if(qRoxo == ROXO_CORRECT){
    //     	correctAnswer = true;
    //     }
    // }
    // if(input.mousePress(SDL_BUTTON_LEFT) && vermelhoBox.hasPoint(click)){
    //     if(qVermelho == VERMELHO_CORRECT){
    //     	correctAnswer = true;
    //     }
    // }
    // if(input.mousePress(SDL_BUTTON_LEFT) && amareloBox.hasPoint(click)){
    //     if(qAmarelo == AMARELO_CORRECT){
    //     	correctAnswer = true;
    //     }
    // }
}


 