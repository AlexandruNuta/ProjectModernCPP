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
