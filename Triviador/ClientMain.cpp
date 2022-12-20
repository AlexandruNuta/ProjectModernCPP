#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

#include <cpr/cpr.h>
#include <crow.h>

int main()
{
	cpr::Response numericQuestions = cpr::Get(cpr::Url{
		"http://localhost:18080/Questions" });
	cpr::Response multipleAnswerQuestions = cpr::Get(cpr::Url{
		"http://localhost:18080/QuestionMultipleAnswer" });
	std::cout << "Please Login:\n";
	std::cout << "Introduce your username and password:\n";
	std::string 
}