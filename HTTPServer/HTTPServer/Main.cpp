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
	crow::SimpleApp app;
	CROW_ROUTE(app, "/")([]() {
		return "Test";
		});
	CROW_ROUTE(app, "/Questions")([]() {
		const std::string Qdb_file = "Questions.sqlite";
	Storage db = createStorage(Qdb_file);
	return "Da";
		});
	app.port(18080).multithreaded().run();
}