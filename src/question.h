#ifndef QUESTION_H
#define QUESTION_H

#include <memory>
#include <vector>

#include "Camera.h"
#include "GameObject.h"
#include "Music.h"
#include "Sprite.h"
#include "State.h"
#include "StateData.h"
#include "Text.h"

#include <fstream>
#include <iostream>

#include <clocale>

class question : public State
{
public:
    question();
    // ~question();
    void update(float);
    void render();
private:
	void input();

	Sprite bg;

	Sprite mestre;
	Rect mestreBox;

	Sprite balao;
	Rect balaoBox;

	Sprite pVerde;
	Rect verdeBox;

	Sprite pVermelho;
	Rect vermelhoBox;

	Sprite pRoxo;
	Rect roxoBox;

	Sprite pAmarelo;
	Rect amareloBox;

	Sprite certo;
	Sprite errado;

	enum Answer {VERDE, ROXO, AMARELO, VERMELHO, E_VERDE, E_ROXO, E_AMARELO, E_VERMELHO};
	Answer answer;

	int i = 0;
	int localResposta;
	
    Music escolha_opcao;
    Music resposta_certa;
    Music resposta_errada;

    Text pergunta;
    Text certa;
    Text errada1;
    Text errada2;
    Text errada3;
};

#endif // QUESTION_H
