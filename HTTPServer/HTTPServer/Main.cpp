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
	const std::string Qdb_file = "Questions.sqlite";
	Storage db = createStorage(Qdb_file);
	db.sync_schema();
	auto questionCount = db.count<Question>();
	/*if (questionCount == 0)
		populateStorage(db);*/
	crow::SimpleApp app;
	CROW_ROUTE(app, "/")([]() {
		return "Test";
		});
	/*CROW_ROUTE(app, "/Questions")([]() {

	return "Da";

		});*/
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

	////////////


	CROW_ROUTE(app, "/add_json")
		.methods("POST"_method)
		([](const crow::request& req) {
		auto x = crow::json::load(req.body);
	if (!x)
		return crow::response(400);
	int sum = x["a"].i() + x["b"].i();
	std::ostringstream os;
	os << sum;
	return crow::response{ os.str() };
			});

	/////////////
	app.port(18080).multithreaded().run();
}