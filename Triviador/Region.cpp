#include "Region.h"
Region::Region()
	:m_isBase(false)
	, m_score(100)
	, m_owned(false)
	, m_North(nullptr)
	, m_East(nullptr)
	, m_South(nullptr)
	, m_West(nullptr)
{
}

bool Region::GetIsBase() const
{
	return m_isBase;
}

bool Region::GetOwned() const
{
	return m_owned;
}

uint16_t Region::GetScore() const
{
	return m_score;
}

void Region::MakeItBase()
{
	if (!m_isBase)
	{
		this->m_isBase = true;
		this->m_score = 300;
		this->m_owned = true;
	}
}

void Region::ChangeOwned()
{
	if (!m_owned)
	{
		this->m_owned = true;
	}
}

void Region::IncrementScore()
{
	this->m_score += 100;
}

void Region::DecrementScore()
{
	this->m_score -= 100;
}

Region* Region::getNorthNeighbour()
{
	return m_North;
}

Region* Region::getEastNeighbour()
{
	return m_East;
}

Region* Region::getSouthNeighbour()
{
	return m_South;
}

Region* Region::getWestNeighbour()
{
	return m_West;
}

void Region::setNorthNeighbour(Region* reg)
{
	m_North = reg;
}

void Region::setEasthNeighbour(Region* reg)
{
	m_East = reg;
}

void Region::setSouthhNeighbour(Region* reg)
{
	m_South = reg;
}

void Region::setWesthNeighbour(Region* reg)
{
	m_West = reg;
}
