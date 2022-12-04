#pragma once
#include <string>
#include <vector>
#include <ostream>
class Question
{
public:
	Question(const std::string& question,const std::vector<std::string>& answears, const int& correctAnswear);
public:
	std::string getQuestion();
	std::vector<std::string> getAnswears();
	int getCorrectAnswear();
	friend std::ostream& operator<<(std::ostream& out, Question game);
	bool isNumerical();
	int IndexCorrectAnswear() const;
private:
	std::string m_question;
	std::vector<std::string> m_answears;
	int m_correctAnswear;
};


