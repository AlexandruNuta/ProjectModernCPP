#pragma once
#include <string>
#include <vector>
#include <ostream>


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

struct Question {
	uint16_t id;
	std::string m_question;
	std::vector<std::string>m_answears;
	int m_correctAnswear;
};
inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"Questions",
			sql::make_column("Id", &Question::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("Question", &Question::m_question),
			sql::make_column("CorrectAnswear", &Question::m_correctAnswear)
			),
		sql::make_table(
			"Answears",
			sql::make_column("Id", &Question::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("First", &Question::m_answears)
			//sql::make_column()
		)
	);
}
using Storage = decltype(createStorage(""));
