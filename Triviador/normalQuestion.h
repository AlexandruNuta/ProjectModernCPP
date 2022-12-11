#pragma once
#include<iostream>
#include <vector>

class normalQuestion
{
public:
	bool verifyAnswer(const std::string& answer);
	void setCorrectAnswear(const int& correctAnswear);
private:
	std::string m_question;
	std::vector<std::string> m_answers;
	int m_correctAnswear;
};

