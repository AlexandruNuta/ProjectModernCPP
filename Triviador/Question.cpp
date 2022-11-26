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

int Question::getCorrectAnswear()
{
	return m_correctAnswear;
}

bool Question::isNumerical()
{
	if (m_answears.size() == 4)
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& out, Question question)
{
	if (question.getAnswears().size() == 0) //Question is numerical
	{
		out << question.getQuestion() << std::endl;
		out << "Introduce numerical answer: ";
	}
	else                                    //Question is not numerical (with 4 answers)
	{
		std::vector<std::string> answers = question.getAnswears();
		out << question.getQuestion() << std::endl;
		out << "1) " << answers[0] << "   2) " << answers[1] << std::endl;
		out << "3) " << answers[2] << "   4) " << answers[3] << std::endl;
		out << "Choose the right answer: ";
	}
	return out;
}
