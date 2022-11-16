#include "Question.h"

Question::Question(const std::string& question,const std::vector<std::string>& answears, const uint8_t& correctAnswear)
	:m_question(question)
	, m_answears(answears)
	, m_correctAnswear(correctAnswear)
{
}

std::string Question::getQuestion()
{
	return m_question;
}

std::vector<std::string> Question::getAnswears()
{
	return m_answears;
}

uint8_t Question::getCorrectAnswear()
{
	return m_correctAnswear;
}
