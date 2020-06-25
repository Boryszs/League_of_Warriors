#pragma once
#include "Champion.h"

class Monster : public Champion {
public:

	Monster(const std::string n, unsigned int l, int he, int st, int de, int ma, int def, int lu) :
		Champion(0, n, l, 0, 0.0, he, st, de, ma, def, lu) {}

	Monster(Champion* const champ) :
		Champion(0, "MONSTER", champ->getLevel(), 0, 0.0, champ->getHealth(), champ->getStrength(), champ->getDexterity(), champ->getMagic(), champ->getDefence(), champ->getLuck()) {}

	virtual int attack() override;
	virtual int block() override;

	virtual Monster* clone() const
	{
		return new Monster(*this);
	}
};