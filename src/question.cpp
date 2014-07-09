#include "question.h"

using namespace std;

question::question() :  bg("img/perguntas/mapaembacado.png"),
						mestre("img/perguntas/mestre.png"),
						balao("img/perguntas/balao.png"),
						pVerde("img/perguntas/verde.png"),
						pRoxo("img/perguntas/roxo1.png"),
						pVermelho("img/perguntas/vermelho.png"),
						pAmarelo("img/perguntas/amarelo.png"),
						certo("img/perguntas/certo.png"),
						errado("img/perguntas/errado.png"),
						pergunta("font/07LogoTypeGothic7.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						certa("font/07LogoTypeGothic7.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						errada1("font/07LogoTypeGothic7.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						errada2("font/07LogoTypeGothic7.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						errada3("font/07LogoTypeGothic7.ttf",34,Text::TEXT_SOLID,"oi",SDL_Color(),0,0),
						escolha_opcao("audio/escolha_opcao.ogg"),
						resposta_certa("audio/resposta_certa.ogg"),
						resposta_errada("audio/resposta_errada.ogg")
{
	StateData::correctAnswer = false;
	StateData::itemRandom = -1;
	StateData::pause = true;

	escolha_opcao.play(1);

	mestre.setScale(0.19);
    mestreBox.setX(Game::getInstance().getWindowWidth() - mestre.getWidth() - 660);
    mestreBox.setY(Game::getInstance().getWindowHeight() - mestre.getHeight() - 40);

 //    balao.setScale(1.1);
	// balaoBox.setX(Game::getInstance().getWindowWidth() - balao.getWidth() + 10);
 //    balaoBox.setY(Game::getInstance().getWindowHeight() - balao.getHeight() - 393);

    balao.setScale(1.1);
	balaoBox.setX(Game::getInstance().getWindowWidth() - balao.getWidth() - 180);
    balaoBox.setY(Game::getInstance().getWindowHeight() - balao.getHeight() - 380);

	pVerde.setScale(0.35);
    verdeBox.setX(Game::getInstance().getWindowWidth() - pVerde.getWidth() - 210);
    verdeBox.setY(Game::getInstance().getWindowHeight() - pVerde.getHeight() - 295);
    verdeBox.setW(pVerde.getWidth());
    verdeBox.setH(pVerde.getHeight());

	pVermelho.setScale(0.35);
    vermelhoBox.setX(Game::getInstance().getWindowWidth() - pVermelho.getWidth() - 210);
    vermelhoBox.setY(Game::getInstance().getWindowHeight() - pVermelho.getHeight() - 195);
    vermelhoBox.setW(pVermelho.getWidth());
    vermelhoBox.setH(pVermelho.getHeight());

    pRoxo.setScale(0.35);
    roxoBox.setX(Game::getInstance().getWindowWidth() - pRoxo.getWidth() - 210);
    roxoBox.setY(Game::getInstance().getWindowHeight() - pRoxo.getHeight() - 95);
    roxoBox.setW(pRoxo.getWidth());
    roxoBox.setH(pRoxo.getHeight());

    pAmarelo.setScale(0.35);
    amareloBox.setX(Game::getInstance().getWindowWidth() - pAmarelo.getWidth() - 210);
    amareloBox.setY(Game::getInstance().getWindowHeight() - pAmarelo.getHeight());
    amareloBox.setW(pAmarelo.getWidth());
    amareloBox.setH(pAmarelo.getHeight());

    //opcao e para tipo de pergunta, ta ok
    int opcao = (rand() % 3);
    int value = 0, index = 0;
	if(opcao == 0){
		cout << opcao << '!' <<endl;
		// escolhe uma linha do arq grammar
		std::ifstream file ("img/grammar.txt");
		value = (rand() % 32);
    	index = value*5 + 1;
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
	    	localResposta = (rand() % 4);
	    	
	    	cout << "grammar" << strCorreta1<<localResposta << endl;
			if(localResposta == 0){
				answer = VERDE;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 +110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    certa.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 1){
				answer = VERMELHO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);
				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    
			    errada1.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
				certa.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 2){
				answer = ROXO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    errada2.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    certa.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 3){
				answer = AMARELO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    errada2.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada3.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    certa.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
        }else{
	        printf("Nao conseguiu abrir\n");
	    }
	    file.close();
	}
	if(opcao == 1){
		std::ifstream file ("img/expressoes.txt");
		value = (rand() % 29);
    	index = value*5 + 1;
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
			
	  		localResposta = (rand() % 4);
	  		cout << "expressoes!" << strCorreta1<<localResposta << endl;
  			if(localResposta == 0){
				answer = VERDE;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 10,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    certa.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 1){
				answer = VERMELHO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);
				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 10,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    
			    errada1.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
				certa.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 2){
				answer = ROXO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 10,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    errada2.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    certa.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 3){
				answer = AMARELO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    errada2.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada3.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    certa.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
        }else{
	        printf("Nao conseguiu abrir\n");
	    }
	    file.close();
	}
	if(opcao == 2){
		std::ifstream file ("img/kanji.txt");
		value = (rand() % 202);
    	index = value*5 + 1;
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
	  		
	  		localResposta = (rand() % 4);
	  		cout << "kanji" << strCorreta1 <<localResposta<< endl;
  			if(localResposta == 0){
				answer = VERDE;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    certa.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 1){
				answer = VERMELHO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);
				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    
			    errada1.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
				certa.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada2.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 2){
				answer = ROXO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    errada2.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    certa.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    errada3.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		    if(localResposta == 3){
				answer = AMARELO;
			    pergunta.setText(strPergunta);
			    certa.setText(strCorreta1);
			    errada1.setText(strErrada1);
			    errada2.setText(strErrada2);
			    errada3.setText(strErrada3);

				pergunta.setPos((balaoBox.getX() - Camera::pos.getX())/2 + 110,(balaoBox.getY() - Camera::pos.getY())/2 + 120,true,true);
			    errada2.setPos((verdeBox.getX() - Camera::pos.getX())/2 - 50,(verdeBox.getY() - Camera::pos.getY())/2 - 40,true,true);
			    errada1.setPos((vermelhoBox.getX() - Camera::pos.getX())/2 - 50,(vermelhoBox.getY() - Camera::pos.getY())/2 - 80,true,true);
			    errada3.setPos((roxoBox.getX() - Camera::pos.getX())/2 - 50,(roxoBox.getY() - Camera::pos.getY())/2 - 150,true,true);
			    certa.setPos((amareloBox.getX() - Camera::pos.getX())/2 - 50,(amareloBox.getY() - Camera::pos.getY())/2 - 180,true,true);
		    }
		}else{
	        printf("Nao conseguiu abrir\n");
	    }
	    file.close();
	}
}

void question::update(float){
	input();
	if(hasRequestedDelete){
		errado.clear();
    	certo.clear();
    	pergunta.clear();
    	certa.clear();
    	errada1.clear();
    	errada2.clear();
    	errada3.clear();
	}
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
    if(localResposta == 0){
	    certa.render(verdeBox.getX() - Camera::pos.getX(),verdeBox.getY() - Camera::pos.getY());
	    errada1.render(vermelhoBox.getX() - Camera::pos.getX(),vermelhoBox.getY() - Camera::pos.getY());
	    errada2.render(roxoBox.getX() - Camera::pos.getX(),roxoBox.getY() - Camera::pos.getY());
	    errada3.render(amareloBox.getX() - Camera::pos.getX(),amareloBox.getY() - Camera::pos.getY());
    }
    if(localResposta == 1){
    	errada1.render(verdeBox.getX() - Camera::pos.getX(),verdeBox.getY() - Camera::pos.getY());
	    certa.render(vermelhoBox.getX() - Camera::pos.getX(),vermelhoBox.getY() - Camera::pos.getY());
	    errada2.render(roxoBox.getX() - Camera::pos.getX(),roxoBox.getY() - Camera::pos.getY());
	    errada3.render(amareloBox.getX() - Camera::pos.getX(),amareloBox.getY() - Camera::pos.getY());
    }
    if(localResposta == 2){
    	errada2.render(verdeBox.getX() - Camera::pos.getX(),verdeBox.getY() - Camera::pos.getY());
	    errada1.render(vermelhoBox.getX() - Camera::pos.getX(),vermelhoBox.getY() - Camera::pos.getY());
	    certa.render(roxoBox.getX() - Camera::pos.getX(),roxoBox.getY() - Camera::pos.getY());
	    errada3.render(amareloBox.getX() - Camera::pos.getX(),amareloBox.getY() - Camera::pos.getY());
    }
    if(localResposta == 3){
    	errada2.render(verdeBox.getX() - Camera::pos.getX(),verdeBox.getY() - Camera::pos.getY());
	    errada1.render(vermelhoBox.getX() - Camera::pos.getX(),vermelhoBox.getY() - Camera::pos.getY());
	    errada3.render(roxoBox.getX() - Camera::pos.getX(),roxoBox.getY() - Camera::pos.getY());
	    certa.render(amareloBox.getX() - Camera::pos.getX(),amareloBox.getY() - Camera::pos.getY());
    }
    
    
    if(StateData::correctAnswer == true && answer == VERDE){
    	i ++;
    	certo.setScale(0.15);
    	certo.render(verdeBox.getX() - Camera::pos.getX() + 150,verdeBox.getY() - Camera::pos.getY() + 10);
    }
    if(StateData::correctAnswer == true && answer == VERMELHO){
    	i ++;
    	certo.setScale(0.15);
    	certo.render(vermelhoBox.getX() - Camera::pos.getX() + 150,vermelhoBox.getY() - Camera::pos.getY() + 10);
    }
    if(StateData::correctAnswer == true && answer == AMARELO){
    	i ++;
    	certo.setScale(0.15);
    	certo.render(amareloBox.getX() - Camera::pos.getX() + 150,amareloBox.getY() - Camera::pos.getY() + 10);
    }
    if(StateData::correctAnswer == true && answer == ROXO){
    	i ++;
    	certo.setScale(0.15);
    	certo.render(roxoBox.getX() - Camera::pos.getX() + 150,roxoBox.getY() - Camera::pos.getY() + 10);
    }
    if(answer == E_VERDE){
    	i ++;
    	errado.setScale(0.15);
    	errado.render(verdeBox.getX() - Camera::pos.getX() + 150,verdeBox.getY() - Camera::pos.getY() + 10);
    }
    if(answer == E_VERMELHO){
    	i ++;
    	errado.setScale(0.15);
    	errado.render(vermelhoBox.getX() - Camera::pos.getX() + 150,vermelhoBox.getY() - Camera::pos.getY() + 10);
    }
    if(answer == E_AMARELO){
    	i ++;
    	errado.setScale(0.15);
    	errado.render(amareloBox.getX() - Camera::pos.getX() + 150,amareloBox.getY() - Camera::pos.getY() + 10);
    }
    if(answer == E_ROXO){
    	i ++;
    	errado.setScale(0.15);
    	errado.render(roxoBox.getX() - Camera::pos.getX() + 150,roxoBox.getY() - Camera::pos.getY() + 10);
    }
    if(i >= 10){
    	hasRequestedDelete = true;  
    	StateData::pause = false;  	
    }
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
        if(answer == VERDE){
        	resposta_certa.play(1);
        	StateData::correctAnswer = true;
        	StateData::itemRandom = (rand() % StateData::itemArray.size());
        }
        else{
	        answer = E_VERDE;
	        StateData::itemRandom = -1;
	        resposta_errada.play(1);
	    }
    }
    if(input.mousePress(SDL_BUTTON_LEFT) && roxoBox.hasPoint(click)){
        if(answer == ROXO){
        	resposta_certa.play(1);
        	StateData::correctAnswer = true;
        	StateData::itemRandom = (rand() % StateData::itemArray.size());
        }
        else{
	        answer = E_ROXO;
	        StateData::itemRandom = -1;
	        resposta_errada.play(1);
	    }
    }
    if(input.mousePress(SDL_BUTTON_LEFT) && vermelhoBox.hasPoint(click)){
        if(answer == VERMELHO){
        	resposta_certa.play(1);
        	StateData::correctAnswer = true;
        	StateData::itemRandom = (rand() % StateData::itemArray.size());
        }
        else{
	        answer = E_VERMELHO;
	        StateData::itemRandom = -1;
	        resposta_errada.play(1);
	    }
    }
    if(input.mousePress(SDL_BUTTON_LEFT) && amareloBox.hasPoint(click)){
        if(answer == AMARELO){
        	resposta_certa.play(1);
        	StateData::correctAnswer = true;
        	StateData::itemRandom = (rand() % StateData::itemArray.size());
        }
        else{
	        answer = E_AMARELO;
	        StateData::itemRandom = -1;
	        resposta_errada.play(1);
	    }
    }
}


 