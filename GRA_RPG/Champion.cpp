#include "Champion.h"
using namespace std;

Champion::Champion(const unsigned id, const std::string n, unsigned int l, unsigned int e, double m, int he, int st, int de, int ma, int def, int lu) :
	id_champion(id), name(n), level(l), experience(e), money(m), health(he), strength(st), dexterity(de), magic(ma), defence(def), luck(lu)
{}

std::ostream& operator<<(std::ostream& out, const Champion& p)
{
	out << "id[ " << p.id_champion << " ]\nNazwaPostaci[ " << p.name << " ]\nPoziom[ " << p.level << " ]\n" <<
		"Xp[ " << p.experience << " ]\nPieniadze[ " << p.money << " ]\n\nZdrowie[ " << p.health << " ]\n" <<
		"Atak[ " << p.strength << " ]\nZrecznosc[ " << p.dexterity << " ]\nMagia[ " << p.magic <<
		" ]\nObrona[ " << p.defence << " ]\nSzczescie[ " << p.luck << " ]\n\n";
	return out;
}


