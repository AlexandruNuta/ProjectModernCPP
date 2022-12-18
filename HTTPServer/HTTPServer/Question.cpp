#include "Question.h"



void populateStorage(Storage& storage)
{
	std::vector<Question> numericQuestions;
	std::vector<QuestionMultipleAnswers>multipleAnswer;
	std::ifstream fin("Questions.txt");
	int lineCounter = 0;
	std::string question;
	std::string answer1;
	std::string answer2;
	std::string answer3;
	std::string answer4;
	std::string rightAnswear;
	while (lineCounter < 300) {
		std::getline(fin, question);
		std::getline(fin,answer1);
		std::getline(fin,answer2);
		std::getline(fin,answer3);
		std::getline(fin,answer4);
		std::getline(fin,rightAnswear);
		QuestionMultipleAnswers temp(0, question, rightAnswear, answer1, answer2, answer3, answer4);
		multipleAnswer.push_back(temp);
		lineCounter = lineCounter + 6;

	}
	while (lineCounter < 400) {
		std::getline(fin, question);
		std::getline(fin, rightAnswear);
		Question temp(0, question,rightAnswear);
		numericQuestions.push_back(temp);
		lineCounter = lineCounter + 2;
	}
	storage.insert_range(numericQuestions.begin(),numericQuestions.end());
	storage.insert_range(multipleAnswer.begin(), multipleAnswer.end());
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
