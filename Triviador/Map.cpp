#include "Map.h"

Map::Map(const uint8_t& rows,const uint8_t& column)
{
	m_map.resize(rows,std::vector<Region>(columns));

}

std::vector<std::vector<Region>> Map::getMap()
{
	return m_map;
}
