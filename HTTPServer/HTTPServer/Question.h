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
	std::vector<std::string>m_answers;
	int m_correctAnswer;
public:
	Question( uint16_t id, std::string question, std::vector<std::string> answer, int correctAnswer);
};
inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"Questions",
			sql::make_column("Id", &Question::m_id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("Question", &Question::m_question),
			sql::make_column("CorrectAnswear", &Question::m_correctAnswer)
			),
		sql::make_table(
			"Answears",
			sql::make_column("Id", &Question::m_id, sql::autoincrement(), sql::primary_key())
			//sql::make_column("First", &Question::m_answers)
			//sql::make_column()
		)
	);
}
using Storage = decltype(createStorage(""));

void populateStorage(Storage& storage);