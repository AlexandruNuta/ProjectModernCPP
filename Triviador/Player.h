#pragma once

#include <vector>

#include "Region.h"

class Player
{
public:
	Player(const std::string& username, const std::string& password, const uint16_t& indexVector);

	std::shared_ptr<Region> GetBase() const;
	std::vector<std::shared_ptr<Region>> GetTerritory() const;
	uint16_t GetIndexVector() const;
	uint16_t TotalScore() const;

private:
	std::string m_username;
	std::string m_password;
	uint16_t m_indexVector;
	std::vector<std::shared_ptr<Region>> m_territory;
};

