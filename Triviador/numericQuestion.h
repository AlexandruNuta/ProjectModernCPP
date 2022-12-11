#pragma once
#include<iostream>

class numericQuestion
{
public:
	int verifyAnswer(const int& answer);
	void setAnswer(int const& answer);


private:
	std::string m_question;
	int m_answer;
};

