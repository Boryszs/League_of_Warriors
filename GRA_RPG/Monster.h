#pragma once
#include "Champion.h"

/// Class Monster Inherits a champion.
class Monster : public Champion {
public:
    /// Constructor Monster cause a champion constructor.
    /// <param name="n"> - Name champion</param>
    /// <param name="l"> - Level champion</param>
    /// <param name="he"> - Health champion </param>
    /// <param name="st"> - Strength champion </param>
    /// <param name="de"> - Dexerity Champion</param>
    /// <param name="ma"> - Magic champion </param>
    /// <param name="def"> - Defence champion </param>
    /// <param name="lu"> - Lucky champion </param>
	Monster(const std::string n, unsigned int l, int he, int st, int de, int ma, int def, int lu) :
		Champion(0, n, l, 0, 0.0, he, st, de, ma, def, lu) {}

	/// Constructor Monster copying constructor.
	/// <param name="champ"> - Pointer object const champ</param>
	Monster(Champion* const champ) :
		Champion(0, "MONSTER", champ->getLevel(), 0, 0.0, champ->getHealth(), champ->getStrength(), champ->getDexterity(), champ->getMagic(), champ->getDefence(), champ->getLuck()) {}

	/// Virtual function attack.
	/// <returns> value attack </returns>
	virtual int attack() override;
	/// Virtual function block.
	/// <returns> value block </returns> 
	virtual int block() override;

	/// Virtual function clone to clone object.
	/// <returns> Pointer object Archer </returns> 
	virtual Monster* clone() const
	{
		return new Monster(*this);
	}
};