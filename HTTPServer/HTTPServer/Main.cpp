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
				{"question",index.m_question},
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
				{"question",index.m_question},
				{"answer",index.m_answer},
				{"answer1",index.m_answers1},
				{"answer2",index.m_answers2},
				{"answer3",index.m_answers3},
				{"answer4",index.m_answers4}

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

	CROW_ROUTE(app, "/RegisterNewUsers").methods("POST"_method)([&db](const crow::request& request) {
		auto data = crow::json::load(request.body);
	for (auto& index : db.iterate<Users>()) {
		if (index.m_username == data["username"].s()) {
			return crow::response(400, "You are already registered");
		}
	}
	Users user;
	user.m_username = data["username"].s();
	user.m_password = data["password"].s();
	db.insert(user);
	return crow::response(200);
		});

	
	app.port(18080).multithreaded().run();
}