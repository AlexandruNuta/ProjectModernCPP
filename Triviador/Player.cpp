#include "Player.h"

Player::Player(std::string username, std::string password)
	:m_username(username)
	,m_password(password)
	,m_isInGame(true)
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

bool Player::getIsInGame()
{
	return m_isInGame;
}

std::vector<std::pair<int, int>> Player::getTerritory()
{
	return m_territory;
}

void Player::addRegion(const std::pair<int, int>& indexes)
{
	m_territory.push_back(indexes);
}

void Player::removeRegion(const std::pair<int, int>& indexes)
{
	m_territory.erase(std::remove(m_territory.begin(), m_territory.end(), indexes), m_territory.end());
}

void Player::changePassword(std::string newPassword)
{
	this->m_password = newPassword;
}

void Player::changeUsername(std::string newUsername)
{
	this->m_username = newUsername;
}

void Player::changeIsInGame()
{
	if (this->m_isInGame == true)
	{
		this->m_isInGame = false;
	}
}
