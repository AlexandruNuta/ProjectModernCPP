#include "Question.h"

Question::Question(const std::string& question,const std::vector<std::string>& answears, const int& correctAnswear)
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

int Question::IndexCorrectAnswear() const
{
	for (auto i = 0; i < m_answears.size(); i++)
		if (stoi(m_answears[i]) == m_correctAnswear)
			return i;
}

std::ostream& operator<<(std::ostream& out, Question question)
{
	if (question.getAnswears().size() == 0) //Question is numerical
	{
		out << question.getQuestion() << std::endl;
	}
	else                                    //Question is not numerical (with 4 answers)
	{
		std::vector<std::string> answers = question.getAnswears();
		out << question.getQuestion() << std::endl;
		out << "1) " << answers[0] << "   2) " << answers[1] << std::endl;
		out << "3) " << answers[2] << "   4) " << answers[3] << std::endl;
	}
	return out;
}
