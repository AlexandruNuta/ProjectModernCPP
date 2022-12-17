#include "normalQuestion.h"

bool normalQuestion::verifyAnswer(const std::string& answer)
{
	if (answer.empty())
	{
		std::cout << "Invalid Answer" << std::endl;
		throw;
	}
	for (int i = 0; i < m_answers.size(); i++)
		if (m_answers[i] == answer)
		{
			if (m_correctAnswer == i)
				return true;
			else
				return false;
		}
	std::cout << "Your answer is not found in the options offered" << std::endl;
	return false;
}

void normalQuestion::setCorrectAnswer(const int& correctAnswer)
{
	m_correctAnswer = correctAnswer;
}
