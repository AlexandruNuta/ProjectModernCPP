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

	void AddRegion(std::shared_ptr<Region> region);
	void RemoveRegion(std::shared_ptr<Region> region);
	bool VerifiVecinity(const std::pair<uint16_t, uint16_t>& coordinates);

	void Conquering(std::shared_ptr<Player> opponent);
	void Elimination();

	friend std::ostream& operator<< (std::ostream& out, std::shared_ptr<Player> player);

private:
	std::string m_username;
	std::string m_password;
	uint16_t m_indexVector;
	std::vector<std::shared_ptr<Region>> m_territory;
};

