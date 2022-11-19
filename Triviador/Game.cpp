#include "Game.h"

Game::Game(Map gameMap, uint8_t numberOfRounds, std::vector<Player> players)
	:m_gameMap(gameMap)
	, m_numberOfRounds(numberOfRounds)
	, m_players(players)
{
}

void Game::gameInitialiseBase(Player player, const std::pair<int, int>& indexes)
{
	m_gameMap.InitializeBase(indexes);
	player.addRegion(indexes);
}

void Game::gameAddRegion(Player player, const std::pair<int, int>& indexes)
{
	m_gameMap.ChangeOwned(indexes);
	player.addRegion(indexes);
}

void Game::removeRegion(Player player, const std::pair<int, int>& indexes)
{
	player.removeRegion(indexes);
}

bool Game::verifyIfScore100(const std::pair<int, int>& indexes)
{
	return m_gameMap.getScore(indexes) == 100;
}

uint16_t Game::calculateScore(Player player)
{
	uint16_t score = 0;
	for (auto it : player.getTerritory())
		score = score + m_gameMap.getScore(it);
	return score;
}

void Game::changeRegionOwner(Player initialPlayer, Player finalPlayer, std::pair<int, int> index)
{
	removeRegion(initialPlayer, index);
	gameAddRegion(finalPlayer, index);
}

void Game::changeBaseOwner(Player initialPlayer, Player finalPlayer)
{
	for (auto it :finalPlayer.getTerritory())
		initialPlayer.addRegion(it);
}

std::vector<Player> Game::getPlayers()
{
	return m_players;
}
