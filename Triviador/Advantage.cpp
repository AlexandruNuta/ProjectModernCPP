#include "Advantage.h"
#include<vector>
void Advantage::answerElimination(const Player& player, const uint8_t& value, Question question)
{
	if (value == 0 && question.isNumerical() == false)
	{
		return;
	}
	else
	{
		std::vector<std::string>answers = question.getAnswers();
		uint8_t correctAnswear = question.getCorrectAnswer();
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
		for (const auto& it : question.getAnswers())
			dif.push_back(stoi(it) - question.getCorrectAnswer());
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

void Advantage::answearChoice(Question question)
{
	std::vector<int> random;
	random.push_back(rand() % question.getCorrectAnswer() / 2 + question.getCorrectAnswer() / 2);
	random.push_back(rand() % question.getCorrectAnswer() / 2);
	random.push_back(rand() % question.getCorrectAnswer() / 2 + question.getCorrectAnswer());
	random.push_back(question.getCorrectAnswer());
	while (random.size())
	{
		int x = rand() % random.size();
		std::cout << random[x] << " ";
		random.erase(random.begin() + x);
	}
}

void Advantage::advantageChoose(Question question) const
{
	std::cout << "Choose an avantage:" << std::endl;
	std::cout << "1. Answer Elimination - Eliminate two wrong answers." << std::endl;
	if (question.isNumerical())
	{
		std::cout << "2. Answear Choice - Add four answers from which you can choose." << std::endl;
		std::cout << "3. Answer Suggestion - Suggest an answer close to the correct one." << std::endl;
	}
	int x;
	std::cin >> x;
	switch (x)
	{
	case 1:
		//answerElimination(player, question);
		break;
	case 2:
		//answerSugestion(question);
		break;
	case 3:
		//answearChoice(question);
		break;
	}
}