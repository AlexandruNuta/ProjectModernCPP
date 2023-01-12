#include "Question.h"

Question::Question(const std::string& question, const std::vector<std::string>& answers, const uint16_t& correctAnswer)
	:m_question(question),
	m_answers(answers),
	m_correctAnswer(correctAnswer),
	m_print(false)
{
}
std::string Question::GetQuestion() const
{
	return m_question;
}

std::vector<std::string> Question::GetAnswers() const
{
	return m_answers;
}

std::string Question::GetCorrectAnswer() const
{
	return m_answers[m_correctAnswer];
}

uint16_t Question::GetIndexCorrectAnswer() const
{
	return m_correctAnswer;
}

bool Question::GetPrint()
{
	if (!m_print)
	{
		m_print = true;
		return false;
	}
	return m_print;
}

std::ostream& operator<<(std::ostream& out, const Question& question)
{
	if (question.GetAnswers().size() == 1)
		out << question.GetQuestion() << std::endl;
	else
	{
		std::vector<std::string> answers = question.GetAnswers();
		out << question.GetQuestion() << std::endl;
		out << "a. " << answers[0] << "   b. " << answers[1] << std::endl;
		out << "c. " << answers[2] << "   d. " << answers[3] << std::endl;
		out << std::endl;
	}
	out << "If you want to choose an advantage, press the '+' key." << std::endl;
	return out;
}