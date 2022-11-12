#pragma once
#include "Map.h"
#include "Player.h"

class Game
{
public:
	Game(Map gameMap, uint8_t numberOfRounds, std::vector<Player> players);

public:
	void gameInitialiseBase(Player player,const std::pair<int, int>& indexes);
	void gameAddRegion(Player player,const std::pair<int, int>& indexes);
	void removeRegion(Player player, const std::pair<int, int>& indexes);
	bool verifyIfScore100(const std::pair<int, int>& indexes);
	
private:
	Map m_gameMap;
	uint8_t m_numberOfRounds;
	std::vector<Player> m_players;
};

