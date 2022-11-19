#include "Interface.h"
#include <fstream>
#include <string>
void main()
{
	std::vector<Player> x;
	Map m(4, 4);
	Game g(m, 3, x);
	Interface i(g);
	i.testFunction(40); 
}