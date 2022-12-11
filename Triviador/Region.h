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
	Region* getNorthNeighbour();
	Region* getEastNeighbour();
	Region* getSouthNeighbour();
	Region* getWestNeighbour();
	void setNorthNeighbour(Region* reg);
	void setEasthNeighbour(Region* reg);
	void setSouthhNeighbour(Region* reg);
	void setWesthNeighbour(Region* reg);

private:
	bool m_isBase;
	bool m_owned;
	uint16_t m_score;
	Region* m_North;
	Region* m_East;
	Region* m_South;
	Region* m_West;
};

