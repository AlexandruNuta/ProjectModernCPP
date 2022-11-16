#include "Question.h"

Question::Question(const std::string& question, std::vector<std::string> answears, const uint8_t& correctAnswear)
	:m_question(question)
	, m_answears(answears)
	, m_correctAnswear(correctAnswear)
{
}
