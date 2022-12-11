#include "Question.h"

Question::Question(const std::string& question,const std::vector<std::string>& answers, const int& correctAnswer)
	:m_question(question)
	, m_answers(answers)
	, m_correctAnswer(correctAnswer)
{
}

std::string Question::getQuestion()
{
	return m_question;
}

std::vector<std::string> Question::getAnswers()
{
	return m_answers;
}

int Question::getCorrectAnswer()
{
	return m_correctAnswer;
}

bool Question::isNumerical()
{
	if (m_answers.size() == 4)
		return false;
	return true;
}

int Question::IndexCorrectAnswer() const
{
	for (auto i = 0; i < m_answers.size(); i++)
		if (stoi(m_answers[i]) == m_correctAnswer)
			return i;
}

std::ostream& operator<<(std::ostream& out, Question question)
{
	if (question.getAnswers().size() == 0) //Question is numerical
	{
		out << question.getQuestion() << std::endl;
	}
	else                                    //Question is not numerical (with 4 answers)
	{
		std::vector<std::string> answers = question.getAnswers();
		out << question.getQuestion() << std::endl;
		out << "1) " << answers[0] << "   2) " << answers[1] << std::endl;
		out << "3) " << answers[2] << "   4) " << answers[3] << std::endl;
	}
	return out;
}
