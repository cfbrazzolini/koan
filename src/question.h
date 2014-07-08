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


	enum CorrectAnswer {VERDE, ROXO, AMARELO, VERMELHO};
	CorrectAnswer answer;

	//BlockTileSet tileSet;
	//TileMap tileMap;
    Music music;
    Text pergunta;
    Text certa;
    Text errada1;
    Text errada2;
    Text errada3;
};

#endif // QUESTION_H
