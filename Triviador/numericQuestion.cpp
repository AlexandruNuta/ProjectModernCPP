#include "numericQuestion.h"

int numericQuestion::verifyAnswer(const int& answer)
{
	if (m_answer - answer)
		return false;
	return true;
}

void numericQuestion::setAnswer(int const& answer)
{
	m_answer = answer;
}

