#include "Interface.h"
#include <fstream>
#include <string>
void main()
{
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
}