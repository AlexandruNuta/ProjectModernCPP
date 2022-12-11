#include "Interface.h"
#include <fstream>
#include <string>

#include <filesystem>
#include <iostream>
#include <memory>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

void numberOfPlayersValidation(uint16_t& numberOfPlayers)
{
	while (!(numberOfPlayers >= 2 && numberOfPlayers <= 4))
	{
		std::cout << "Numarul minim de jucatori este 2,iar numarul maxim este 4." << std::endl;
		std::cout << "Va rugam sa introduceti un nou numar de jucatori: "; std::cin >> numberOfPlayers;
		std::cout << std::endl;
	}
}

void signUpPlayers(std::vector<Player>& players, uint16_t numberOfPlayers)
{
	uint16_t registeredPlayers = 0;
	std::string name, password;
	while (registeredPlayers < numberOfPlayers)
	{
		std::cout << "Jucatorul " << registeredPlayers + 1 << " sa introduca numele si parola: " << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> name;
		std::cout << "Parola:" << std::endl; std::cin >> password;
		Player player(name, password);
		players.push_back(player);
		registeredPlayers++;
	}
}

void computeMapSizeAndNrRounds(uint16_t numberOfPlayers,uint16_t& mapLines, uint16_t& mapColumns, uint16_t& nrRounds)
{
	switch (numberOfPlayers)
	{
	case 2:
	{
		mapLines = 3;
		mapColumns = 3;
		nrRounds = 5;
		break;
	}
	case 3:
	{
		mapLines = 5;
		mapColumns = 3;
		nrRounds = 4;
		break;
	}
	case 4:
	{
		mapLines = 6;
		mapColumns = 4;
		mapColumns = 4;
		break;
	}
	default:
	{
		throw numberOfPlayers;
		break;
	}
	}
}

void main()
{
	std::string nume, parola;
	uint16_t numarJucatori;
	std::vector<Player> players;

	std::cout << "INCEPUTUL JOCULUI." << std::endl;
	std::cout << "Introduceti numarul de jucatori: ";

	std::cin >> numarJucatori;
	numberOfPlayersValidation(numarJucatori);
	std::cout << "Succes!" << std::endl;
	signUpPlayers(players, numarJucatori);

	uint16_t liniiMapa, coloaneMapa, nrRunde;
	computeMapSizeAndNrRounds(numarJucatori, liniiMapa, coloaneMapa, nrRunde);
	Map map(liniiMapa, coloaneMapa);

	Game game(map, nrRunde, players);
	Interface interface(game);

	interface.stageChooseBase();
	interface.stageChoseRegion();

}

