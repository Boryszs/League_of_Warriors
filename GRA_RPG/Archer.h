#pragma once
#include "Champion.h"

class Archer : public Champion {
public:
	// Tymczasowy konstruktor
	Archer(const unsigned id, const std::string n, unsigned int l, unsigned int e, double m, int he, int st, int de, int ma, int def, int lu) :
		Champion(id, n, l, e, m, he, st, de, ma, def, lu) {}

	virtual int attack() override;
	virtual int block() override;

	//komentarz
	virtual Archer* clone() const
	{
		return new Archer(*this);
	}
};