#pragma once
#include <string>
#include <vector>
#include <algorithm>

class Player
{
public:
	Player(std::string username, std::string password);
	std::string getUsername();
	std::string getPassword();
	bool getIsInGame();
	std::vector<std::pair<int, int>> getTerritory();

public:
	void addRegion(const std::pair<int, int>& indexes);
	void removeRegion(const std::pair<int, int>& indexes);
	void changePassword(std::string newPassword);
	void changeUsername(std::string newUsername);
	void changeIsInGame();

private:
	std::string m_username;
	std::string m_password;
	bool m_isInGame;
	std::vector < std::pair<int, int> > m_territory;
};

