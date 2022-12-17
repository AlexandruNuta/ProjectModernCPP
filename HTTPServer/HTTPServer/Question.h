#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;
//class Question
//{
//public:
//	Question(const std::string& question, const std::vector<std::string>& answears, const int& correctAnswear);
//public:
//	std::string getQuestion();
//	std::vector<std::string> getAnswears();
//	int getCorrectAnswear();
//	friend std::ostream& operator<<(std::ostream& out, Question game);
//	bool isNumerical();
//	int IndexCorrectAnswear() const;
//private:
//	std::string m_question;
//	std::vector<std::string> m_answears;
//	int m_correctAnswear;
//};

class Question {
public:
	uint16_t m_id;
	std::string m_question;
	std::string m_answer;
public:
	Question( uint16_t id, std::string question,std::string answer);
	Question();
};
class QuestionMultipleAnswers {
public:
	uint16_t m_id;
	std::string m_question;
	std::string m_answer;
	std::string m_answers1;
	std::string m_answers2;
	std::string m_answers3;
	std::string m_answers4;
public:
	QuestionMultipleAnswers(uint16_t id, std::string question, std::string answer, std::string answers1, std::string answers2, std::string answers3, std::string answers4);
	QuestionMultipleAnswers();
};
inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"NumericQuestion",
			sql::make_column("id", &Question::m_id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("question", &Question::m_question),
			sql::make_column("answer", &Question::m_answer)
		),
		sql::make_table(
			"MultipleAnswersQuestion",
			sql::make_column("id", &QuestionMultipleAnswers::m_id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("question", &QuestionMultipleAnswers::m_question),
			sql::make_column("answer", &QuestionMultipleAnswers::m_answer),
			sql::make_column("answer1", &QuestionMultipleAnswers::m_answers1),
			sql::make_column("answer2", &QuestionMultipleAnswers::m_answers2),
			sql::make_column("answer3", &QuestionMultipleAnswers::m_answers3),
			sql::make_column("answer4", &QuestionMultipleAnswers::m_answers4)
		)
	);
}
using Storage = decltype(createStorage(""));

void populateStorage(Storage& storage);