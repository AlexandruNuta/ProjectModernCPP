#include "Question.h"



void populateStorage(Storage& storage)
{
	std::vector<Question> questions;
	std::ifstream fin("XDD.txt");
	int lineCounter = 0;
	std::string question;
	std::string answear;
	std::string rightAnswear;
	int numeralRightAnswear;

	/*std::vector<Question> questions;
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

		Question questionObject(0,question, answears,);
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
	storage.insert_range(questions.begin(), questions.end());*/
}

Question::Question(uint16_t id, std::string question, std::string answer)
	:m_id(id),
	m_question(question),
	m_answer(answer)
{
}

Question::Question()
{
}

QuestionMultipleAnswers::QuestionMultipleAnswers(uint16_t id, std::string question, std::string answer, std::string answers1, std::string answers2, std::string answers3, std::string answers4)
	:m_id(id),
	m_question(question),
	m_answer(answer),
	m_answers1(answers1),
	m_answers2(answers2),
	m_answers3(answers3),
	m_answers4(answers4)

{
}

QuestionMultipleAnswers::QuestionMultipleAnswers()
{
}

Users::Users(const uint16_t& id,const std::string& username,const std::string& password)
	:m_id(id),
	m_username(username),
	m_password(password)
{
}

Users::Users()
{
}
