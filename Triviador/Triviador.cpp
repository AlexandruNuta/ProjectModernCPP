#include "Interface.h"
#include <fstream>
#include <string>
void main()
{
	/*
	Player p1("Codrut", "ppp");
	Player p2("Nuta", "ppp");
	Player p3("George", "ppp");
	Player p4("Dani", "ppp");

	std::vector<Player> x;

	x.push_back(p1);
	x.push_back(p2);
	x.push_back(p3);
	x.push_back(p4);

	Map m(4, 4);
	Game g(m, 3, x);
	Interface i(g);
	i.stageChooseBase();
	i.stageChoseRegion();
	*/
	std::cout << "INCEPUTUL JOCULUI." << std::endl;
	std::cout << "Introduceti numarul de jucatori:";
	uint16_t numarJucatori;
	std::cin >> numarJucatori;
	//	std::cout << numarJucatori << std::endl;
	std::string nume, parola;
	while(numarJucatori!=5)
	switch (numarJucatori)
	{
	case 0:
		std::cout << "Numarul minim de jucatori este 2,iar numarul maxim este 4." << std::endl;
		std::cout << "Va rugam sa introduceti un nou numar de jucatori:"; std::cin >> numarJucatori;
		std::cout << std::endl;
		break;
	case 1:
		std::cout << "Numarul minim de jucatori este 2,iar numarul maxim este 4." << std::endl;
		std::cout << "Va rugam sa introduceti un nou numar de jucatori:"; std::cin >> numarJucatori;
		std::cout<< std::endl;
		break;
	case 2:
	{
		std::cout << "Succes!" << std::endl;
		std::cout << "Jucatorul 1 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p1(nume, parola);
		std::cout << "Jucatorul 2 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p2(nume, parola);
		std::vector<Player> players;
		players.push_back(p1);
		players.push_back(p2);
		Map map(3, 3);
		Game game(map, 5, players);
		Interface i(game);
		i.stageChooseBase();
		i.stageChoseRegion();
		break;
	}
	case 3:
	{
		std::cout << "Succes!" << std::endl;
		std::cout << "Jucatorul 1 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p1(nume, parola);
		std::cout << "Jucatorul 2 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p2(nume, parola);
		std::cout << "Jucatorul 3 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p3(nume, parola);
		std::vector<Player> players;
		players.push_back(p1);
		players.push_back(p2);
		players.push_back(p3);
		Map map(5, 3);
		Game game(map, 4, players);
		Interface i(game);
		i.stageChooseBase();
		i.stageChoseRegion();
		break;
	}
	case 4:
	{
		std::cout << "Succes!" << std::endl;
		std::cout << "Jucatorul 1 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p1(nume, parola);
		std::cout << "Jucatorul 2 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p2(nume, parola);
		std::cout << "Jucatorul 3 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p3(nume, parola);
		std::cout << "Jucatorul 4 sa introduca numele si parola:" << std::endl;
		std::cout << "Numele:" << std::endl; std::cin >> nume;
		std::cout << "Parola:" << std::endl; std::cin >> parola;
		Player p4(nume, parola);
		std::vector<Player> players;
		players.push_back(p1);
		players.push_back(p2);
		players.push_back(p3);
		players.push_back(p4);
		Map map(6, 4);
		Game game(map, 4, players);
		Interface i(game);
		i.stageChooseBase();
		i.stageChoseRegion();
		break;
	}
	}
}
	//Interface i(game);
	//i.stageChooseBase();
	//i.stageChoseRegion();
