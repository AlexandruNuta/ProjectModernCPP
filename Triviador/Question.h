#pragma once
#include <string>
#include <vector>
#include <cstdint>
class Question
{
public:
	Question(const std::string& question,const std::vector<std::string>& answears, const uint8_t& correctAnswear);
public:
	std::string getQuestion();
	std::vector<std::string> getAnswears();
	uint8_t getCorrectAnswear();
private:
	std::string m_question;
	std::vector<std::string> m_answears;
	uint8_t m_correctAnswear;
};


