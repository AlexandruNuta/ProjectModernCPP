#include <iostream>
#include <filesystem>
#include <memory>
#include <string>
#include "Question.h"

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;


int main()
{
	const std::string db_file = "game_database.sqlite";
	Storage db = createStorage(db_file);
	db.sync_schema();
	/*if (questionCount == 0)
		populateStorage(db);*/
	crow::SimpleApp app;
	CROW_ROUTE(app, "/")([]() {
		return "Test";
		});
	CROW_ROUTE(app, "/Questions")([&db]() {
	std::vector<crow::json::wvalue>Questions;
	for (const auto& index : db.iterate<Question>())
	{
		Questions.push_back(crow::json::wvalue
			{
				{"id",index.m_id},
				{"name",index.m_question},
				{"answer",index.m_answer}

			});
	}
	return crow::json::wvalue(Questions);
		});


	CROW_ROUTE(app, "/QuestionMultipleAnswer")([&db]() {
		std::vector < crow::json::wvalue>Questions;
	for (const auto& index : db.iterate<QuestionMultipleAnswers>())
	{
		Questions.push_back(crow::json::wvalue
			{
				{"id",index.m_id},
				{"name",index.m_question},
				{"answer",index.m_answer},
				{"answers1",index.m_answers1},
				{"answers2",index.m_answers2},
				{"answers3",index.m_answers3},
				{"answers4",index.m_answers4}

			});
	}
	return crow::json::wvalue(Questions);
		});


	CROW_ROUTE(app, "/InceputulJocului")
		([] {
		crow::json::wvalue x;
	x["message"] = "InceputulJocului!";
	return x;
			});


	CROW_ROUTE(app, "/NumberOfPlayers/<int>")([](int numberOfPlayers) {
		if (numberOfPlayers > 4) {
			return crow::response(400);
		}
			std::ostringstream os;
			os << "In this game will be " << numberOfPlayers << " players";
			return crow::response(os.str());
		});

	
	app.port(18080).multithreaded().run();
}