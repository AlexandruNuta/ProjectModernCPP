#pragma once
#include <cstdint>

class Region
{
public:
	Region();
	bool getIsBase();
	bool getOwned();
	int getScore();

private:

	bool m_isBase;
	bool m_owned;
	uint16_t score;
};

