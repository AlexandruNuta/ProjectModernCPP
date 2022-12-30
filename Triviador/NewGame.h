#pragma once

#include "Question.h"
#include "Player.h"
#include "Map.h"

class NewGame
{
public:
	void ReadQuestion();
	void InitializeMapAndRounds(const uint16_t& numberPlayers);
	void InitializeGame();

	Question GetNumericalQuestion() const;
	Question GetQuestionMultipleChoice() const;

private:
	Map m_map;
	std::vector<Question> m_questions;
	std::vector<std::shared_ptr<Player>> m_players;
	uint16_t roundsNumber;
};
