#include <vector>
#include <algorithm>
#include <random>

#include "Avantage.h"

void Avantage::Menu(const Question& question)
{
	uint16_t x;
	std::cout << std::endl << "AVANTAJE" << std::endl;
	if (question.GetAnswers().size() == 1)
	{
		std::cout << "1. Receives 4 answers, one of which is correct." << std::endl;
		std::cout << "2. Receives a value close to the correct answer." << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cin >> x;
		switch (x)
		{
		case 1:
			break;
		case 2:
			break;
		}
	}
	else
	{
		std::cout << "1. Eliminate 2 wrong answers." << std::endl;
		std::cout << "2. Exit" << std::endl;
		std::cin >> x;
		switch (x)
		{
		case 1:
			RemoveWrongAnswers(question);
			break;
		}
	}
}

void Avantage::RemoveWrongAnswers(Question question)
{
	uint16_t answersRemoved = 0;
	std::vector<uint16_t> indexQuestions = { 0, 1, 2, 3 };
	std::shuffle(indexQuestions.begin(), indexQuestions.end(), std::mt19937{ std::random_device{}() });
	for (int i = 0; i < indexQuestions.size(); i++)
	{
		if (indexQuestions[i] != question.GetIndexCorrectAnswer())
		{
			question.RemoveAnswer(indexQuestions[i]);
			answersRemoved++;
		}
		if (answersRemoved == 2)
			break;
	}
	std::cout << std::endl << question.GetQuestion() << std::endl;
	for (int i = 0; i < question.GetAnswers().size(); i++)
		if (question.GetAnswers()[i] != "")
			std::cout << (char)(i + 97) << ". " << question.GetAnswers()[i] << "   ";
	std::cout << std::endl;
}
