#pragma once

#include "Question.h"
#include "Player.h"
#include "Map.h"
#include "Avantage.h"

class NewGame
{
public:
	void ReadQuestion();
	void InitializeMapAndRounds(const uint16_t& numberPlayers);
	void InitializeGame();

	Question GetNumericalQuestion();
	Question GetQuestionMultipleChoice();

	void StageChooseBase();
	void StageChoseRegion();

	void VerifyAttackCoordinates(std::shared_ptr<Player> player, uint16_t& coordinate1, uint16_t& coordinate2);
	bool VerifyGameContinues() const;
	void DetermineWinner(std::shared_ptr<Player> player, std::shared_ptr<Region> region);
	void StageDuels();

	void Ranking();

private:
	Map m_map;
	std::vector<Question> m_questions;
	std::vector<std::shared_ptr<Player>> m_players;
	uint16_t roundsNumber;
};
