#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <tuple>
#include <random>

#include "NewGame.h"

void NewGame::ReadQuestion()
{
	std::ifstream f("Questions.txt");
	std::string question, answer;
	std::vector<std::string> answers;
	uint16_t m_correctAnswer;
	const uint16_t questionMultipleChoice = 300;
	const uint16_t numericalQuestion = 400;
	uint16_t lineCounter = 0;
	while (lineCounter < questionMultipleChoice)
	{
		const uint16_t numberAnswers = 4;
		const uint16_t nextQuestion = 6;
		std::getline(f, question);
		for (int i = 0; i < numberAnswers; i++)
		{
			std::getline(f, answer);
			answers.push_back(answer);
		}
		std::getline(f, answer);
		Question questionObject(question, answers, std::stoi(answer));
		m_questions.push_back(questionObject);
		lineCounter = lineCounter + nextQuestion;
		answers.clear();
	}
	while (lineCounter < numericalQuestion)
	{
		const uint16_t indexCorrectAnswer = 0;
		const uint16_t nextQuestion = 2;
		std::getline(f, question);
		std::getline(f, answer);
		answers.push_back(answer);
		Question questionObject(question, answers, indexCorrectAnswer);
		m_questions.push_back(questionObject);
		lineCounter = lineCounter + nextQuestion;
		answers.clear();
	}
	f.close();
}

void VerifyNumberPlayers(uint16_t& numberPlayers)
{
	const uint16_t minimPlayers = 2;
	const uint16_t maximPlayers = 4;
	std::cout << std::endl;
	while (numberPlayers < minimPlayers || numberPlayers > maximPlayers)
	{
		std::cout << "At least 2 players and a maximum of 4 can participate in the game." << std::endl;
		std::cout << "How many players participate in the game?" << std::endl;
		std::cin >> numberPlayers;
		std::cout << std::endl;
	}
}

void NewGame::InitializeMapAndRounds(const uint16_t& numberPlayers)
{
	switch (numberPlayers)
	{
	case 2:
		m_map = Map(3, 3);
		roundsNumber = 5;
		break;
	case 3:
		m_map = Map(5, 3);
		roundsNumber = 4;
		break;
	case 4:
		m_map = Map(6, 4);
		roundsNumber = 5;
		break;
	}
}
void Login(std::vector<std::shared_ptr<Player>>& m_players, const uint16_t& numberPlayers)
{
	std::string username, password;
	for (int i = 0; i < numberPlayers; i++)
	{
		std::cout << "LOGIN" << std::endl;
		std::cout << "Username: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> password;
		std::shared_ptr<Player> player = std::make_shared<Player>(username, password, i);
		m_players.push_back(player);
		std::cout << std::endl;
	}
}

void NewGame::InitializeGame()
{
	uint16_t numberPlayers;
	std::cout << "How many players participate in the game?" << std::endl;
	std::cin >> numberPlayers;
	VerifyNumberPlayers(numberPlayers);
	InitializeMapAndRounds(numberPlayers);
	Login(m_players, numberPlayers);
}

Question NewGame::GetNumericalQuestion() const
{
	const uint16_t numberNumericalQuestion = 50;
	const uint16_t numberQuestionMultipleChoice = 50;
	srand(time(NULL));
	return m_questions[rand() % numberNumericalQuestion + numberQuestionMultipleChoice];
}

Question NewGame::GetQuestionMultipleChoice() const
{
	const uint16_t numberQuestionMultipleChoice = 50;
	srand(time(NULL));
	return m_questions[rand() % numberQuestionMultipleChoice];
}