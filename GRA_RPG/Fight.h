#pragma once
#include <iostream>
#include "Champion.h"
#include "string"

using namespace std;

/// Class support fighting between player vs monster or player vs player.
class Fight
{
	Champion* champ1{ nullptr };
	Champion* champ2{ nullptr };
	bool flag_use_skil;

public:
	/// Default constructor class Fight.
	Fight() {}
	/// Constructor Class Fight
	/// <param name="c1"> - pointer to first character</param>
	/// <param name="c2"> - pointer of second character</param>
	/// <returns></returns>
	Fight(Champion *c1, Champion *c2) : champ1(c1->clone()), champ2(c2->clone())
	{
		flag_use_skil = false;
	}
	/// Destructor class Fight
	~Fight()
	{
		delete champ1;
		delete champ2;
	}

	/// Function set health.
	/// <param name="champ"> - Basic helth champion</param> 
	void heal(const Champion* const champ);
	/// Function starts fight between characters.
	void startFigft();

	friend std::ostream& operator<<(std::ostream& out, const Fight& p);

	/// Get health from first character.
	/// <returns>Health as String</returns>
	string getChamp1() { return to_string(champ1->getHealth()); }
	/// Get health from second character.
	/// <returns>Health as String</returns>
	string getChamp2() { return to_string(champ2->getHealth()); }
};