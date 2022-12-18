#pragma once
#include "Game.h"
#include "Interface.h"
#include <vector>
#include <string>
class Advantage
{
public:
	enum class Advantages :uint8_t
	{
		answerElimination,
		answerChoice,
		answerSuggestion
	};
public:
	void answerElimination(const Player& player, const uint8_t& value, Question question);
	int answerSugestion(Question question);
	void answearChoice(Question question);
	int advantageChoose();
};

