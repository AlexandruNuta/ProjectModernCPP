#include "Region.h"

Region::Region()
{
	this->m_isBase = false;
	this->m_owned = false;
	this->score = 100;
}

bool Region::getIsBase()
{
	return m_isBase;
}

bool Region::getOwned()
{
	return m_isBase;
}

int Region::getScore()
{
	return score;
}

void Region::makeItBase()
{
	if (!m_isBase)
	{
		this->m_isBase = true;
	}
}

void Region::changeOwned()
{
	if (!m_owned)
	{
		this->m_owned = true;
	}
}

void Region::incrementScore()
{
	this->score += 100;
}

void Region::decrementScore()
{
	this->score -= 100;
}
 //TEST