#include "Lobby.h"

Lobby::Lobby(const uint16_t& numberOfPlayers,const Map& map,const std::vector<Player>& players)
	:m_numberOfPlayers(numberOfPlayers)
	,m_map(map)
	,m_players(players)
{
}

int Lobby::GetNumberOfPlayers()
{
	return m_numberOfPlayers;
}

Map Lobby::GetMap()
{
	return m_map;
}

std::vector<Player> Lobby::GetPlayers()
{
	return m_players;
}
