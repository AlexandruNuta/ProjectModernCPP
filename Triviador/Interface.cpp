#include "Interface.h"
#include <fstream>
#include <string>
#include <chrono>
#include <tuple>
#include <algorithm>

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
	srand(time(NULL));
	if (mustBeNumerical)
	{
		return m_allQuestion[rand() % 50 + 50];
	}
	return m_allQuestion[rand() % 100];
}

std::tuple<int, int, int> Interface::IndexAnswerTime(Question question, int index)
{
	int answer;
	int time;
	std::cout << question;
	AskForInput(m_game.getPlayers()[index]);

	using Clock = std::chrono::high_resolution_clock;
	auto start = Clock::now();
	std::cin >> answer;
	auto end = Clock::now();

	answer = answer - question.getCorrectAnswear();
	answer = std::abs(answer);

	time = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	return std::make_tuple(index, answer, time);
}

bool compareTuples(std::tuple<int, int, int> a, std::tuple<int, int, int> b)
{
	if (std::get<1>(a) == std::get<1>(b))
	{
		return std::get<2>(a) <= std::get<2>(b);
	}
	return std::get<1>(a) < std::get<1>(b);
}

void Interface::TopPlayersForOneQuestion(Question question)
{
	std::vector<std::tuple<int, int, int>> forSorting;

	for (int index = 0; index < m_game.getPlayers().size(); index++)
	{
		forSorting.push_back(IndexAnswerTime(question, index));
	}
	std::sort(forSorting.begin(), forSorting.end(), compareTuples);


	std::vector<Player> sortedPlayers;

	for (int i = 0; i < forSorting.size(); i++)
	{
		sortedPlayers.push_back(m_game.getPlayers()[std::get<0>(forSorting[i])]);
	}
	m_game.changePlayerVectors(sortedPlayers);
}

void Interface::AskForInput(Player player)
{
	std::cout << player.getUsername() << ", please input your answer: ";
}

void Interface::stageChooseBase()
{
	std::cout << std::endl << std::endl << "STAGE 1: CHOOSE BASES" << std::endl << std::endl;

	Question question = getRandomQuestion(true);
	TopPlayersForOneQuestion(question);

	std::cout << std::endl << "Correct Answer: " << question.getCorrectAnswear() << std::endl << std::endl;

	for (Player player : m_game.getPlayers())
	{
		int coordinate1, coordinate2;

		std::cout << m_game;
		std::cout << player.getUsername() << ", choose region based on coordinates" << std::endl;
		std::cout << "Introduce first coordinate:";
		std::cin >> coordinate1;
		std::cout << "Introduce second coordinate:";
		std::cin >> coordinate2;
		while (m_game.isOwned(std::make_pair(coordinate1, coordinate2)))
		{
			std::cout << "!Base already occupied!" << std::endl;
			std::cout<<"Please choose an unocuppied region based on coordinates" << std::endl;
			std::cout << "Introduce first coordinate:";
			std::cin >> coordinate1;
			std::cout << "Introduce second coordinate:";
			std::cin >> coordinate2;
		}
		m_game.gameInitialiseBase(player, std::make_pair(coordinate1, coordinate2));
		std::cout << "Base initialised with succes!" << std::endl << std::endl;
	}
}

void Interface::stageChoseRegion()
{

	std::cout << std::endl << std::endl << "STAGE 2: CHOOSE REGIONS" << std::endl << std::endl;

	Question question = getRandomQuestion(true);
	TopPlayersForOneQuestion(question);

	std::cout << std::endl << "Correct Answer: " << question.getCorrectAnswear() << std::endl << std::endl;

	for (Player player : m_game.getPlayers())
	{
		int coordinate1, coordinate2;

		std::cout << m_game;
		std::cout << player.getUsername() << ", choose region based on coordinates" << std::endl;
		std::cout << "Introduce first coordinate:";
		std::cin >> coordinate1;
		std::cout << "Introduce second coordinate:";
		std::cin >> coordinate2;
		while (m_game.isOwned(std::make_pair(coordinate1, coordinate2)))
		{
			std::cout << "!Region already occupied!" << std::endl;
			std::cout << "Please choose an unocuppied region based on coordinates" << std::endl;
			std::cout << "Introduce first coordinate:";
			std::cin >> coordinate1;
			std::cout << "Introduce second coordinate:";
			std::cin >> coordinate2;
		}
		m_game.gameAddRegion(player, std::make_pair(coordinate1, coordinate2));
		std::cout << "Region added with succes!" << std::endl << std::endl;
	}
}

void Interface::stageDuel()
{
	std::cout << "The actual map is:" << std::endl;
	std::cout<<m_game;
}
