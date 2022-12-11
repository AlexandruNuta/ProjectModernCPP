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
	app.port(18080).multithreaded().run();
}