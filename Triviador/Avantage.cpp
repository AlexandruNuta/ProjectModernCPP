#include "Avantage.h"

void Avantage::Menu(const Question& question)
{
	uint16_t x;
	std::cout << "AVANTAJE" << std::endl;
	if (question.GetAnswers().size() == 1)
	{
		std::cout << "1. Receives 4 answers, one of which is correct." << std::endl;
		std::cout << "2. Receives a value close to the correct answer." << std::endl;
		std::cout << "Press any other key to exit the menu." << std::endl;
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
		std::cout << "Press any other key to exit the menu." << std::endl;
		std::cin >> x;
		switch (x)
		{
		case 1:
			break;
		}
	}
}
