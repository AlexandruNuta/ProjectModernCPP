#include "Interface.h"
#include <fstream>
#include <string>

Interface::Interface(const Game& game)
{
	m_game = game;
	std::ifstream fin("XDD.txt");
	int lineCounter = 0;
	std::string question;
	std::string answear;
	std::string rightAnswear;
	int numeralRightAnswear; 
	while (lineCounter < 300)
	{
		std::vector<std::string> answears;
		
		std::getline(fin, question);
		std::getline(fin, answear);
		answears.push_back(answear);
		std::getline(fin, answear);
		answears.push_back(answear);
		std::getline(fin, answear);
		answears.push_back(answear);
		std::getline(fin, answear);
		answears.push_back(answear);
		std::getline(fin, rightAnswear);
		numeralRightAnswear = std::stoi(rightAnswear);
		
		Question questionObject(question, answears, numeralRightAnswear);
		m_allQuestion.push_back(questionObject);
		lineCounter = lineCounter + 6;
	}
	while (lineCounter < 400)
	{
		std::vector<std::string> answears;
		std::getline(fin, question);
		std::getline(fin, rightAnswear);
		numeralRightAnswear = std::stoi(rightAnswear);

		Question questionObject(question, answears, numeralRightAnswear);
		m_allQuestion.push_back(questionObject);
		lineCounter = lineCounter + 2;
	}
}

void Interface::testFunction(int questionNumber)
{
	std::cout << m_allQuestion[questionNumber];
}

Question Interface::getRandomQuestion(bool mustBeNumerical)
{
	if (mustBeNumerical)
	{
		return m_allQuestion[rand() % 50 + 50];
	}
	return m_allQuestion[rand() % 100];
}

void Interface::stageChooseBase()
{
	Question question = getRandomQuestion(true);
	std::cout << question;
}
