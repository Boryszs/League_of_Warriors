#pragma once
#include <iostream>
#include "Champion.h"
#include "string"


//kom
using namespace std;

class Fight
{
	Champion* champ1{ nullptr };
	Champion* champ2{ nullptr };
	bool flag_use_skil;

public:
	Fight() {}
	Fight(Champion *c1, Champion *c2) : champ1(c1->clone()), champ2(c2->clone())
	{
		flag_use_skil = false;
	}

	~Fight()
	{
		delete champ1;
		delete champ2;
	}

	void startFigft();

	friend std::ostream& operator<<(std::ostream& out, const Fight& p);

	string getChamp1() { return to_string(champ1->getHealth()); }
	string getChamp2() { return to_string(champ2->getHealth()); }
};