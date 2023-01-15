#pragma once
#include "Question.h"

class Avantage
{
public:
	void Menu(const Question& question);

	void RemoveWrongAnswers(Question question);
	void CloseValue(Question question);
	void MultipleChoice(Question question);
};
