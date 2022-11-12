#pragma once
#include "Region.h"
#include <iostream>
#include <vector>
#include <cstdint>
class Map
{
public:
	Map(const uint8_t& rows,const uint8_t& columns);
	Map() = default;
public:
	std::vector<std::vector<Region>> getMap();
	friend std::ostream& operator<<(std::ostream& out,Map map);
private:
	std::vector<std::vector<Region>> m_map;
};

