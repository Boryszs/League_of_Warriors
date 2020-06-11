#pragma once
#include "Champion.h"

//kkkk
class Archer : public Champion {
public:
	Archer(const unsigned id, const std::string n, unsigned int l, unsigned int e, double m, int he, int st, int de, int ma, int def, int lu) :
		Champion(id, n, l, e, m, he, st, de, ma, def, lu) {}

	virtual int attack() override;
	virtual int block() override;

	//komentarz123
	virtual Archer* clone() const
	{
		return new Archer(*this);
	}
};