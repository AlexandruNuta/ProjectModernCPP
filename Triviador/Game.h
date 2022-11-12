#pragma once
#include "Map.h"
#include "Player.h"

class Game
{
public:
	Game(Map gameMap, uint8_t numberOfRounds, std::vector<Player> players);
	
private:
	Map m_gameMap;
	uint8_t m_numberOfRounds;
	std::vector<Player> m_players;
};

