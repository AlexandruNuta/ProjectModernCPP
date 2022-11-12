#include "Player.h"

Player::Player(std::string username, std::string password)
	:m_username(username)
	,m_password(password)
{
}

std::string Player::getUsername()
{
	return m_username;
}

std::string Player::getPassword()
{
	return m_password;
}

std::vector<std::pair<int, int>> Player::getTerritory()
{
	return m_territory;
}
