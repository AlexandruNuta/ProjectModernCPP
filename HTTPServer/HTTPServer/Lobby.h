#pragma once
#include <vector>
#include "Map.h"
#include "Player.h"
class Lobby
{
public:
	Lobby(const uint16_t& numberOfPlayers, const Map& map,const std::vector<Player>&players);
	Lobby();

	int GetNumberOfPlayers();
	Map GetMap();
	std::vector<Player> GetPlayers();
private:
	uint16_t m_numberOfPlayers;
	Map m_map;
	std::vector<Player> m_players;
};

