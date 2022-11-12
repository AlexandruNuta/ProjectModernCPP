#pragma once
#include <string>
#include <vector>

class Player
{
public:
	Player(std::string username, std::string password);
	std::string getUsername();
	std::string getPassword();
	std::vector<std::pair<int, int>> getTerritory();

private:
	std::string m_username;
	std::string m_password;
	std::vector < std::pair<int, int> > m_territory;
};

