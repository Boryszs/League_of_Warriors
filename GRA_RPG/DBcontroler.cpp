#include "DBcontroler.h"
#include <string>
#include "Warrior.h"
#include "Archer.h"
#include "Wizzard.h"

using namespace std;

DBcontroler::DBcontroler()
{
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "gamerpg", 3306, NULL, 0);
}

bool DBcontroler::checkUser(int id)
{
	string querry = "SELECT * FROM users WHERE idUsers = " + to_string(id) + ";";
	const char* q = querry.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if (row != nullptr)
			return true;
		return false;
	}
	else
		return false;
}

bool DBcontroler::checkUser(std::string login)
{
	string querry = "SELECT * FROM users WHERE login = '" + login + "';";
	const char* q = querry.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if (row != nullptr)
			return true;
		return false;
	}
	else
		return false;
}

bool DBcontroler::addUser(const std::string login, const std::string password)
{
	string querry = "INSERT INTO users (idUsers, login, passwd) VALUES (null, '" + login + "', '" + password + "');";
	const char* q = querry.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
		return true;
	else
		return false;
}

MYSQL_ROW DBcontroler::getUser(std::string login, std::string password)
{
	string pass = "SELECT MD5('" + password + "');";
	const char* p = pass.c_str();
	qstate = mysql_query(conn, p);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		string query = "SELECT idUsers FROM users WHERE login = '" + login + "' and passwd = '" + row[0] + "';";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);

			return row;
		}
	}

	return nullptr;
}

MYSQL_ROW DBcontroler::getChampions(int id)
{
	string qerry = "SELECT idHeroes FROM heroes WHERE Users_idUsers = " + to_string(id) + ";";
	const char* q = qerry.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			cout << "id postaci = " << row[0] << endl;
		}
		return row;
	}
	return nullptr;
}

Champion* DBcontroler::getChampion(int id)
{
	Champion* champ = nullptr;
	string qerry = "SELECT * FROM heroe WHERE idHeroe = " + to_string(id) + ";";
	const char* q = qerry.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		const unsigned int idHeroes = atoi(row[0]);
		const string name = row[2];
		const unsigned int level = atoi(row[3]);
		const unsigned int experience = atoi(row[4]);
		const double money = stod(row[5]);
		const int health = atoi(row[6]);
		const int strength = atoi(row[7]);
		const int dexterity = atoi(row[8]);
		const int magic = atoi(row[9]);
		const int defence = atoi(row[10]);
		const int luck = atoi(row[11]);

		if (*row[1] == '1')
			champ = new Warrior(idHeroes, name, level, experience, money, health, strength, dexterity, magic, defence, luck);
		else if (*row[1] == '2')
			champ = new Archer(idHeroes, name, level, experience, money, health, strength, dexterity, magic, defence, luck);
		else if (*row[1] == '3')
			champ = new Wizzard(idHeroes, name, level, experience, money, health, strength, dexterity, magic, defence, luck);
	}
	return champ;
}


void DBcontroler::updateChampion(Champion* champ)
{
	string qerry = "UPDATE heroe SET level=" + to_string(champ->getLevel()) + ",exp=" + to_string(champ->getExperince()) + ",money=" + to_string(champ->getMoney()) + ",health=" + to_string(champ->getHealth()) + ",strength=" + to_string(champ->getStrength()) + ",dexterity=" + to_string(champ->getDexterity()) + ",magic=" + to_string(champ->getMagic()) + ",defence=" + to_string(champ->getDefence()) + ",luck=" + to_string(champ->getLuck()) + " WHERE idHeroe=" + to_string(champ->getId()) + ";";
	const char* q = qerry.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{
	
	}
	else
	{
		cout << "error connect database"<< endl;

	}
}