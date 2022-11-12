#include "Region.h"

Region::Region()
{
	this->m_isBase = false;
	this->m_owned = false;
	this->m_score = 100;
}

bool Region::GetIsBase() const
{
	return m_isBase;
}

bool Region::GetOwned() const
{
	return m_isBase;
}

int Region::GetScore() const
{
	return m_score;
}

void Region::MakeItBase()
{
	if (!m_isBase)
	{
		this->m_isBase = true;
		this->m_score = 300;
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