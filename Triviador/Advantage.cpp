#include "Advantage.h"
#include<vector>
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
				answers.erase(answers.begin() + correctAnswear + 1);

			}
		}
	}




}

int Advantage::answerSugestion(Question question)
{
	int left = INT_MAX, right = INT_MAX;
	std::vector<int> dif;
	if (question.isNumerical())
	{
		for (const auto& it : question.getAnswears())
			dif.push_back(stoi(it) - question.getCorrectAnswear());
		for (auto it : dif)
		{
			if (it < 0 && abs(it) < abs(left))
				left = it;
			if (it > 0 && it < right)
				right = it;
		}
	}
	if (left == INT_MAX)
		left = 0;
	if (right == INT_MAX)
		right = 0;
	return(abs(left) + right);
}
