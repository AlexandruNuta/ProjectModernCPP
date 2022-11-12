#include "Map.h"

Map::Map(const uint8_t& rows,const uint8_t& columns)
{
	m_map.resize(rows,std::vector<Region>(columns));

}
std::vector<std::vector<Region>> Map::getMap()
{
	return m_map;
}

std::ostream& operator<<(std::ostream& out,Map map)
{
	for (auto row = 0; row <map.m_map.size(); row++)
	{
		for (auto column = 0; column < map.m_map[row].size(); column++)
		{
			out << "Region: " << row << column << std::endl;
			out << "Is base: " << map.m_map[row][column].getIsBase() << std::endl;
			out << "Score: " << map.m_map[row][column].getScore() << std::endl;
			out << "Owned: " << map.m_map[row][column].getOwned() << std::endl;
		}
		out<<std::endl;
	}
	return out;
}
