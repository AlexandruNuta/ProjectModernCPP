#include "normalQuestion.h"

bool normalQuestion::verifyAnswer(const std::string& answer)
{
	for (int i = 0; i < m_answers.size(); i++)
		if (m_answers[i] == answer)
		{
			if (m_correctAnswear == i)
				return true;
			else
				return false;
		}
	std::cout << "Your answer is not found in the options offered" << std::endl;
	return false;
}

void normalQuestion::setCorrectAnswear(const int& correctAnswear)
{
	m_correctAnswear = correctAnswear;
}
