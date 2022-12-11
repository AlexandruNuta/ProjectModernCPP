#include "Question.h"

//Question::Question(const std::string& question,const std::vector<std::string>& answears, const int& correctAnswear)
//	:m_question(question)
//	, m_answears(answears)
//	, m_correctAnswear(correctAnswear)
//{
//}
//
//std::string Question::getQuestion()
//{
//	return m_question;
//}
//
//std::vector<std::string> Question::getAnswears()
//{
//	return m_answears;
//}
//
//int Question::getCorrectAnswear()
//{
//	return m_correctAnswear;
//}
//
//bool Question::isNumerical()
//{
//	if (m_answears.size() == 4)
//		return false;
//	return true;
//}
//
//int Question::IndexCorrectAnswear() const
//{
//	for (auto i = 0; i < m_answears.size(); i++)
//		if (stoi(m_answears[i]) == m_correctAnswear)
//			return i;
//}
//
//std::ostream& operator<<(std::ostream& out, Question question)
//{
//	if (question.getAnswears().size() == 0) //Question is numerical
//	{
//		out << question.getQuestion() << std::endl;
//	}
//	else                                    //Question is not numerical (with 4 answers)
//	{
//		std::vector<std::string> answers = question.getAnswears();
//		out << question.getQuestion() << std::endl;
//		out << "1) " << answers[0] << "   2) " << answers[1] << std::endl;
//		out << "3) " << answers[2] << "   4) " << answers[3] << std::endl;
//	}
//	return out;
//}

void populateStorage(Storage& storage)
{
	std::vector<Question> questions;
	std::ifstream fin("XDD.txt");
	int lineCounter = 0;
	std::string question;
	std::string answear;
	std::string rightAnswear;
	int numeralRightAnswear;
	while (lineCounter < 300)
	{
		std::vector<std::string> answears;

		std::getline(fin, question);
		std::getline(fin, answear);
		answears.push_back(answear);
		std::getline(fin, answear);
		answears.push_back(answear);
		std::getline(fin, answear);
		answears.push_back(answear);
		std::getline(fin, answear);
		answears.push_back(answear);
		std::getline(fin, rightAnswear);
		numeralRightAnswear = std::stoi(rightAnswear);

		Question questionObject(0,question, answears, numeralRightAnswear);
		questions.push_back(questionObject);
		lineCounter = lineCounter + 6;
	}
	while (lineCounter < 400)
	{
		std::vector<std::string> answears;
		std::getline(fin, question);
		std::getline(fin, rightAnswear);
		numeralRightAnswear = std::stoi(rightAnswear);

		Question questionObject(0,question, answears, numeralRightAnswear);
		questions.push_back(questionObject);
		lineCounter = lineCounter + 2;
	}
	storage.insert_range(questions.begin(), questions.end());
}

Question::Question(uint16_t id, std::string question, std::vector<std::string> answer, int correctAnswer)
	:m_id(id),
	m_question(question),
	m_answers(answer),
	m_correctAnswer(correctAnswer)
{
}
