#pragma once
#include "Region.h"
#include <iostream>
#include <vector>
#include <cstdint>
class Map
{
public:
	Map() = default;
	Map(const uint8_t& rows, const uint8_t& columns);
	std::vector<std::vector<Region>> GetMap() const;
	uint16_t getScore(const std::pair<int, int>& indexes);

public:
	friend std::ostream& operator<<(std::ostream& out, Map map);
	void InitializeBase(const std::pair<int, int>& index);
	void ChangeOwned(const std::pair<int, int>& index);
	void IncrementRegion(const std::pair<int, int>& index);
	void DecrementRegion(const std::pair<int, int>& index);
	bool IsOwned(std::pair<int, int> coord);
	std::pair<int, int> size();

private:
	std::vector<std::vector<Region>> m_map;
};

