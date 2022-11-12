#pragma once
#include <cstdint>

class Region
{
public:
	Region();
	bool GetIsBase() const;
	bool GetOwned() const;
	uint16_t GetScore() const;

public:
	void MakeItBase();
	void ChangeOwned();
	void IncrementScore();
	void DecrementScore();

private:
	bool m_isBase;
	bool m_owned;
	uint16_t m_score;
};

