#pragma once
#include <string>
#include <vector>
#include <ostream>
class Question
{
public:
	Question(const std::string& question,const std::vector<std::string>& answers, const int& correctAnswer);
public:
	std::string getQuestion();
	std::vector<std::string> getAnswers();
	int getCorrectAnswer();
	friend std::ostream& operator<<(std::ostream& out, Question game);
	bool isNumerical();
	int IndexCorrectAnswer() const;
private:
	std::string m_question;
	std::vector<std::string> m_answers;
	int m_correctAnswer;
};


