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
		answearElimination,
		answearChoice,
		answearSuggestion
	};
public:
	void answearElimination(const Player& player, const uint8_t& value,Question question);

};

