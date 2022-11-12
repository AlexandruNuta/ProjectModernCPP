#include "Game.h"

Game::Game(Map gameMap, uint8_t numberOfRounds, std::vector<Player> players)
	:m_gameMap(gameMap)
	,m_numberOfRounds(numberOfRounds)
	,m_players(players)
{
}
