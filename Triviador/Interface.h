#pragma once
#include "Game.h"
#include "Question.h"
#include <vector>
#include <random>
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
	Question getRandomQuestion(bool mustBeNumerical);
	std::tuple<int,int,int> IndexAnswerTime(Question question, int index);
	void TopPlayersForOneQuestion(Question question);
	void AskForInput(Player player);

	void stageChooseBase();
	void stageChoseRegion();
	void stageDuel();

private:
	Game m_game;
	std::vector<Question> m_allQuestion;
};

