#include "Region.h"
Region::Region()
	:m_isBase(false)
	,m_score(100)
	,m_owned(false)
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