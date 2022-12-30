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

template <typename T>
T AskForInput(std::shared_ptr<Player> player)
{
	T answer;
	std::cout << player << ", please input your answer: ";
	std::cin >> answer;
	return answer;
}

std::tuple<uint16_t, uint16_t, uint16_t> IndexAnswerTime(const Question& question, std::shared_ptr<Player> player, const uint16_t& index)
{
	int answer;
	float time;
	std::cout << question;

	using Clock = std::chrono::high_resolution_clock;
	auto start = Clock::now();
	answer = AskForInput<int>(player);
	auto end = Clock::now();

	answer = answer - std::stoi(question.GetCorrectAnswer());
	answer = std::abs(answer);

	time = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	return std::make_tuple(index, answer, time);
}

bool compareTuples(const std::tuple<uint16_t, uint16_t, uint16_t>& a, const std::tuple<uint16_t, uint16_t, uint16_t>& b)
{
	if (std::get<1>(a) == std::get<1>(b))
	{
		return std::get<2>(a) <= std::get<2>(b);
	}
	return std::get<1>(a) < std::get<1>(b);
}

void TopPlayersForOneQuestion(const Question& question, std::vector<std::shared_ptr<Player>>& players)
{
	std::vector<std::tuple<uint16_t, uint16_t, uint16_t>> forSorting;

	for (int index = 0; index < players.size(); index++)
		forSorting.push_back(IndexAnswerTime(question, players[index], index));
	std::sort(forSorting.begin(), forSorting.end(), compareTuples);

	std::vector<std::shared_ptr<Player>> sortedPlayers;

	for (int i = 0; i < forSorting.size(); i++)
		sortedPlayers.push_back(players[std::get<0>(forSorting[i])]);
	players = sortedPlayers;
}

void ReadCoordinates(uint16_t& coordinate1, uint16_t& coordinate2)
{
	std::cout << "Introduce first coordinate: ";
	std::cin >> coordinate1;
	std::cout << "Introduce second coordinate: ";
	std::cin >> coordinate2;
}
void NewGame::StageChooseBase()
{
	std::cout << std::endl << std::endl << "STAGE 1: CHOOSE BASES" << std::endl << std::endl;
	auto copyPlayers = std::make_unique<std::vector<std::shared_ptr<Player>>>(m_players);
	Question question = GetNumericalQuestion();
	TopPlayersForOneQuestion(question, *copyPlayers);
	std::cout << std::endl << "Correct Answer: " << question.GetCorrectAnswer() << std::endl;
	for (auto player : *copyPlayers)
	{
		uint16_t coordinate1 = 0, coordinate2 = 0;
		std::cout << m_map;
		std::cout << player << ", choose region based on coordinates." << std::endl;
		ReadCoordinates(coordinate1, coordinate2);

		while (coordinate1 > m_map.size().first - 1 || coordinate2 > m_map.size().second - 1)
		{
			std::cout << "The region does not exist. Please choose a valid region based on coordinates." << std::endl;
			ReadCoordinates(coordinate1, coordinate2);
		}
		while (m_map.GetMap()[coordinate1][coordinate2]->GetOwned())
		{
			std::cout << "Base already occupied. Please choose an unocuppied region based on coordinates." << std::endl;
			ReadCoordinates(coordinate1, coordinate2);
		}
		std::shared_ptr<Region> region = m_map.GetMap()[coordinate1][coordinate2];
		region->SetBase(player->GetIndexVector() + 1);
		player->AddRegion(region);
		std::cout << "Base initialised with succes!" << std::endl << std::endl;
	}
	std::cout << "All the bases have been chosen!" << std::endl << std::endl << "Final map:";
	std::cout << m_map << std::endl << std::endl;
}

void NewGame::StageChoseRegion()
{
	std::cout << std::endl << std::endl << "STAGE 2: CHOOSE REGIONS" << std::endl << std::endl;
	while (m_map.CheckIfEmptyRegions())
	{
		Question question = GetNumericalQuestion();
		TopPlayersForOneQuestion(question, m_players);
		std::cout << std::endl << "Correct Answer: " << question.GetCorrectAnswer() << std::endl << std::endl;

		uint16_t placeRanking = 0;
		for (auto player : m_players)
		{
			uint16_t numberOfRegionsToBeSelected = m_players.size() - placeRanking;

			while (numberOfRegionsToBeSelected && m_map.CheckIfEmptyRegions())
			{
				uint16_t coordinate1 = 0, coordinate2 = 0;

				std::cout << m_map;
				std::cout << player << ", choose region based on coordinates." << std::endl;
				ReadCoordinates(coordinate1, coordinate2);
				while (coordinate1 > m_map.size().first - 1 || coordinate2 > m_map.size().second - 1)
				{
					std::cout << "The region does not exist. Please choose a valid region based on coordinates." << std::endl;
					ReadCoordinates(coordinate1, coordinate2);
				}
				while (m_map.GetMap()[coordinate1][coordinate2]->GetOwned())
				{
					std::cout << "Region already occupied. Please choose an unocuppied region based on coordinates." << std::endl;
					ReadCoordinates(coordinate1, coordinate2);

				}
				std::shared_ptr<Region> region = m_map.GetMap()[coordinate1][coordinate2];
				region->SetOwned(player->GetIndexVector() + 1);
				player->AddRegion(region);
				std::cout << "Region added with succes!" << std::endl << std::endl;
				numberOfRegionsToBeSelected--;
			}
			placeRanking++;
		}
	}
	std::cout << "All regions are owned!" << std::endl << "Final map:" << std::endl;
	std::cout << m_map << std::endl << std::endl;
}