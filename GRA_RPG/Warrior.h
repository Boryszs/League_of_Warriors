#pragma once
#include "Champion.h"

class Warrior : public Champion {
public:

	Warrior(const unsigned id, const std::string n, unsigned int l, unsigned int e, double m, int he, int st, int de, int ma, int def, int lu) :
		Champion(id, n, l, e, m, he, st, de, ma, def, lu) {}

	virtual Warrior* clone() const
	{
		return new Warrior(*this);
	}

	virtual int attack() override;
	virtual int block() override;
};