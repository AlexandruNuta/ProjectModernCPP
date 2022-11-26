#include "Interface.h"
#include <fstream>
#include <string>
#include <chrono>

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

std::pair<int, int> Interface::AnswerAndTime(Question question, Player player)
{
	int answer;
	int time;
	std::cout << question;

	using Clock = std::chrono::high_resolution_clock;
	auto start = Clock::now();
	std::cin >> answer;
	auto end = Clock::now();

	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	return std::make_pair(answer, time);
}

void Interface::stageChooseBase()
{
	Question question = getRandomQuestion(true);
	//to be continued....
}
