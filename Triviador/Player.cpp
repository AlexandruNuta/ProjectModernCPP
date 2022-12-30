#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const uint16_t& indexVector)
	:m_username(username),
	m_password(password),
	m_indexVector(indexVector)
{
}

std::shared_ptr<Region> Player::GetBase() const
{
	const uint16_t baseIndex = 0;
	return m_territory[baseIndex];
}

std::vector<std::shared_ptr<Region>> Player::GetTerritory() const
{
	return m_territory;
}

uint16_t Player::GetIndexVector() const
{
	return m_indexVector;
}

uint16_t Player::TotalScore() const
{
	uint16_t totalScore = 0;
	for (const auto& region : m_territory)
		totalScore = totalScore + region->GetScore();
	return totalScore;
}

