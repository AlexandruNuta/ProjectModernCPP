#pragma once
#include "Map.h"
#include "Player.h"

class Game
{
public:
	Game() = default;
	Game(Map gameMap, uint8_t numberOfRounds, std::vector<Player> players);

public:
	void gameInitialiseBase(Player player,const std::pair<int, int>& indexes);
	void gameAddRegion(Player player,const std::pair<int, int>& indexes);
	void removeRegion(Player player, const std::pair<int, int>& indexes);
	bool verifyIfScore100(const std::pair<int, int>& indexes);
	uint16_t calculateScore(Player player);
	void changeRegionOwner(Player initialPlayer, Player finalPlayer, std::pair<int, int> index); //finalPlayer e castigatorul rundei.
	void changeBaseOwner(Player initialPlayer, Player finalPlayer); //finalPlayer e castigatorul rundei.
	std::vector<Player> getPlayers();
	uint8_t getRounds();
	friend std::ostream& operator<<(std::ostream& out, Game game);
	bool isOwned(std::pair<int, int> coord);
	uint8_t getNrRounds();
	std::vector<std::vector<Region>> GetMap();
	std::pair<int, int> GetSize();

private:
	Map m_gameMap;
	uint8_t m_numberOfRounds;
	std::vector<Player> m_players;
};

