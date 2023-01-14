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

int Lobby::GetNumberOfRounds()
{
	return m_numberOfRounds;
}

Map Lobby::GetMap()
{
	return m_map;
}

std::vector<Player> Lobby::GetPlayers()
{
	return m_players;
}

void Lobby::SetNumberOfPlayers(uint16_t numberOfPlayers)
{
	m_numberOfPlayers = numberOfPlayers;
}

void Lobby::SetNumberOfRounds(uint16_t numberOfPlayers)
{
	switch (numberOfPlayers)
	{
	case 2:
		m_numberOfRounds = 5;
		break;
	case 3:
		m_numberOfRounds = 4;
		break;
	case 4:
		m_numberOfRounds = 5;
		break;
	}
}

void Lobby::SetMap(Map map)
{
	m_map = map;
}

void Lobby::SetPlayers(std::vector<Player> players)
{
	m_players = players;
}
