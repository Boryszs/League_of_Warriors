#pragma once
#include <iostream>
//aa
/// Class Champion use to create character.
class Champion
{
protected:
	const unsigned int id_champion;
	const std::string name;

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
	/// Constructor Champion.
	/// <param name="write"> - The inscription that will be shown on the button </param>     
	/// <param name="id"> - Id champion in database</param>    
	/// <param name="n"> - Name champion</param>    
	/// <param name="l"> - Level champion</param>    
	/// <param name="e"> - Experience champion  </param>    
	/// <param name="m"> - Money champion </param>    
	/// <param name="he"> - Health champion </param>  
	/// <param name="st"> - Strength champion </param>  
	/// <param name="de"> - Dexerity Champion</param>  
	/// <param name="ma"> - Magic champion </param>  
	/// <param name="def"> - Defence champion </param>  
	/// <param name="lu"> - Lucky champion </param>
	Champion(const unsigned id, const std::string n, unsigned int l, unsigned int e, double m, int he, int st, int de, int ma, int def, int lu);

	/// Virtual function attack.
	virtual int attack() { return 0; }
	/// Virtual function block.
	virtual int block() { return 0; }
	///Function return Helath the value to heal the hero.
	int heal();
	/// Function set Health.
	/// <param name="hp"> - Helth champion </param> 
	void setHealth(int hp) { health = hp; }

	/// Virtual method clone copy pointer.
	virtual Champion* clone() const = 0;

	/// Function get Health champion.
	int getHealth() const { return health; }
	/// Function get Name champion.
	std::string getName() { return name; }
	/// Showing a value represent champion.
	friend std::ostream& operator<<(std::ostream& out, const Champion& p);

	/// Function add Health.
	/// <param name="hp"> - Value to addition to health</param> 
	void addHealth(int hp) { health += hp; }
	/// Function add Strength.
	/// <param name="hp"> - Value to addition to strength</param> 
	void addStrength(int stren) { strength += stren; }
	/// Function add Dexterity.
	/// <param name="hp"> - Value to addition to Dexterity/param>
	void addDexterity(int dex) { dexterity += dex; }
	/// Function add Magic.
	/// <param name="hp"> - Value to addition to magic</param>
	void addMagic(int mag) { magic += mag; }
	/// Function add Health.
	/// <param name="hp"> - Value to addition to health</param>
	void addDefence(int def) { defence += def; }
	/// Function add Lucky.
	/// <param name="hp"> - Value to addition to lucky</param>
	void addLuck(int luc) { luck += luc; }
	/// Function add Money.
	/// <param name="hp"> - Value to addition to Money</param> 
	void addMoney(int mon) { money += mon; }
	/// Function add Experience.
	/// <param name="hp"> - Value to addition to experience</param> 
	void addExperience(int exp);
	/// Function add Money.
	/// <param name="hp"> - Value to addition to money</param>
	void takeMoney(double mon);
	
	/// Get Id.
	/// <returns> Id champion</returns>
	int getId()
	{
		return id_champion;
	}
	/// Get Experience.
	/// <returns> Experience </returns>
	int getExperince()
	{
		return experience;
	}
	/// Get Level.
	/// <returns> Level</returns>
	int getLevel()
	{
		return level;
	}
	/// Get Money.
	/// <returns> Money </returns>
	int getMoney()
	{
		return money;
	}
	/// Get Strength.
	/// <returns> Strength </returns>
	int getStrength()
	{
		return strength;
	}
	/// Get Dexterity.
	/// <returns> Dexterity </returns>
	int getDexterity()
	{
		return dexterity;
	}
	/// Get Magic.
	/// <returns> Magic </returns>
	int getMagic()
	{
		return magic;
	}
	/// Get Defence.
	/// <returns> Experience </returns>
	int getDefence()
	{
		return defence;
	}
	/// Get Lucky.
	/// <returns> Lucky </returns>
	int getLuck()
	{
		return luck;
	}
};