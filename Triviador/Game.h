#pragma once
#include "Map.h"
#include "Player.h"

class Game
{
public:

private:
	Map m_gameMap;
	uint8_t m_numberOfRounds;
	std::vector<Player> m_players;
};

