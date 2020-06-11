#pragma once
#include <iostream>

class Champion
{
private:
	const unsigned int id_champion;
	const std::string name;

protected:
	unsigned int level;
	unsigned int experience;
	double money;

	int health;
	int strength;
	int dexterity;
	int magic;
	int defence;
	int luck;

public:
	Champion(const unsigned id, const std::string n, unsigned int l, unsigned int e, double m, int he, int st, int de, int ma, int def, int lu);

	virtual int attack() { return 0; }
	virtual int block() { return 0; }
	//virtual int skill();		-- implementowanie w czasie walki na arenie --

	int getHealth() { return health; }
	std::string getName() { return name; }

	friend std::ostream& operator<<(std::ostream& out, const Champion& p);

	// dodawanie w bazie oraz w klasie 
	void addHealth(int hp) { health += hp; }
	void addStrength(int stren) { strength += stren; }
	void addDexterity(int dex) { dexterity += dex; }
	void addMagic(int mag) { magic += mag; }
	void addDefence(int def) { defence += def; }
	void addLuck(int luc) { luck += luc; }
	void addMoney(int mon) { money += mon; }
	
	int getId()
	{
		return id_champion;
	}

	int getExperince()
	{
		return experience;
	}

	int getLevel()
	{
		return level;
	}

	int getMoney()
	{
		return money;
	}

	int getStrength()
	{
		return strength;
	}
	int getDexterity()
	{
		return dexterity;
	}
	int getMagic()
	{
		return magic;
	}
	int getDefence()
	{
		return defence;
	}
	int getLuck()
	{
		return luck;
	}

};