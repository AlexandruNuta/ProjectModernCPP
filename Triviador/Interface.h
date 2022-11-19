#pragma once
#include "Game.h"
#include "Question.h"
#include <vector>
class Interface
{
public:
	Interface() = default;
	Interface(const Game& game);

public:
	/*
	* Functie care testeaza daca s-a facut citirea bine
	* din fisierul txt
	* Afiseaza intrebare cu numarul "questionNumber"
	* O apelez in Triviador.cpp
	*/
	void testFunction(int questionNumber);
private:
	Game m_game;
	std::vector<Question> m_allQuestion;
};

