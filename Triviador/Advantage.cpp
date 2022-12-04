#include "Advantage.h"

void Advantage::answearElimination(const Player& player, const uint8_t& value, Question question)
{
	if (value == 0 && question.isNumerical() == false)
	{
		return;
	}
	else
	{
		std::vector<std::string>answers = question.getAnswears();
		uint8_t correctAnswear = question.getCorrectAnswear();
		if (correctAnswear == 0)
		{
			answers.erase(answers.begin() + correctAnswear + 1);
			answers.erase(answers.begin() + correctAnswear + 2);
		}
		else
		{

			if (correctAnswear == 3)
			{
				answers.erase(answers.begin() + correctAnswear - 1);
				answers.erase(answers.begin() + correctAnswear - 2);

			}
			else
			{
				answers.erase(answers.begin() + correctAnswear - 1);
				answers.erase(answers.begin() + correctAnswear +1);

			}
		}
	}




}
