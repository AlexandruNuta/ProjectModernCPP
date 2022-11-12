#include "Map.h"

Map::Map(const uint8_t& rows, const uint8_t& columns)
{
	m_map.resize(rows, std::vector<Region>(columns));
}

std::vector<std::vector<Region>> Map::GetMap() const
{
	return m_map;
}

void Map::InitializeBase(const std::pair<int, int>& index)
{
	m_map[index.first][index.second].MakeItBase();
}

void Map::ChangeOwned(const std::pair<int, int>& index)
{
	m_map[index.first][index.second].ChangeOwned();
}

void Map::IncrementRegion(const std::pair<int, int>& index)
{
	m_map[index.first][index.second].IncrementScore();
}

void Map::DecrementRegion(const std::pair<int, int>& index)
{
	m_map[index.first][index.second].DecrementScore();
}

std::ostream& operator<<(std::ostream& out, Map map)
{
	out << "MAP:" << std::endl;
	out << "Legend: R = region, B = Base, S = Score, O = Owned" << std::endl << std::endl;
	for (auto row = 0; row < map.m_map.size(); row++)
	{
		for (auto column = 0; column < map.m_map[row].size(); column++)
		{
			out << "R:" << row << column;
			out << " B:" << map.m_map[row][column].GetIsBase();
			out << " S:" << map.m_map[row][column].GetScore();
			out << " O:" << map.m_map[row][column].GetOwned();
			out << "  ";
		}
		out << std::endl;
	}
	return out;
}
