#pragma once
#include <vector>
#include "Map.h"
#include "Player.h"
class Lobby
{
public:
	Lobby(const uint16_t& numberOfPlayers, const Map& map,const std::vector<Player>&players);
	Lobby()=default;

	int GetNumberOfPlayers();
	int GetNumberOfRounds();
	Map GetMap();
	std::vector<Player> GetPlayers();
	void SetNumberOfPlayers(uint16_t numberOfPlayers);
	void SetNumberOfRounds(uint16_t numberOfRounds);
	void SetMap(Map map);
	void SetPlayers(std::vector<Player> players);
	void addPlayer(const std::string& name, const std::string& password);
private:
	uint16_t m_numberOfPlayers;
	uint16_t m_numberOfRounds;
	Map m_map;
	std::vector<Player> m_players;
};

