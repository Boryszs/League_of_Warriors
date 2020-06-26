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
	string querry = "INSERT INTO users (idUsers, login, passwd) VALUES (null, '" + login + "',md5( '" + password + "'));";
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
		string query = "SELECT idUsers FROM users WHERE login = '" + login + "' and passwd = md5('" + password + "');";
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

MYSQL_RES* DBcontroler::getChampions(int id)
{
	string qerry = "SELECT * FROM `heroes` INNER JOIN `heroe` ON heroes.idHeroes=heroe.idHeroe WHERE `Users_idUsers` = " + to_string(id) + ";";
	const char* q = qerry.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		return res;
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
		//cout << row[0];
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

MYSQL_ROW DBcontroler::getProf(int id)
{
	string query = "SELECT class_heroe FROM heroe WHERE idHeroe="+to_string(id)+";";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);

			return row;
	}


	return nullptr;
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


void DBcontroler::addHeroes(int idUser)
{
	string qerry = "INSERT INTO heroes VALUES ("+to_string(idUser)+",(SELECT idHeroe FROM heroe ORDER BY idHeroe DESC LIMIT 1));";
	const char* q = qerry.c_str();
	qstate = mysql_query(conn, q);
	cout << qerry;
	if (!qstate)
	{

	}
	else
	{
		cout << "error connect database1" << endl;

	}
}

void DBcontroler::addChampion(Champion* champ,int class_hero ,int idUser)
{
	string qerry = "INSERT INTO heroe (idHeroe,class_heroe, name, level, exp, money, health, strength, dexterity, magic, defence, luck) VALUES(null, "+ to_string(class_hero)+",'"+champ->getName()+"',"+to_string(champ->getLevel()) + "," + to_string(champ->getExperince()) + "," + to_string(champ->getMoney()) + "," + to_string(champ->getHealth()) + "," + to_string(champ->getStrength()) + "," + to_string(champ->getDexterity()) + "," + to_string(champ->getMagic()) + "," + to_string(champ->getDefence()) + "," + to_string(champ->getLuck())+ ");";
	const char* q = qerry.c_str();
	qstate = mysql_query(conn, q);
	cout << qerry;
	if (!qstate)
	{
		
		addHeroes(idUser);
	}
	else
	{
		cout << "error connect database" << endl;

	}
}

void DBcontroler::deleteHeroes(int idUser, int idChampion)
{
	string qerry = "DELETE FROM heroes WHERE Users_idUsers="+to_string(idUser) +" and "+"idHeroes="+ to_string(idChampion) +";";
	const char* q = qerry.c_str();
	qstate = mysql_query(conn, q);
	cout << qerry;
	if (!qstate)
	{
		deleteHeroe(idChampion);
	}
	else
	{
		cout << "error connect database" << endl;

	}
}

void DBcontroler::deleteHeroe(int idChamp)
{
	string qerry = "DELETE FROM heroe WHERE idHeroe=" + to_string(idChamp) + ";";
	const char* q = qerry.c_str();
	qstate = mysql_query(conn, q);
	cout << qerry;
	if (!qstate)
	{

	}
	else
	{
		cout << "error connect database" << endl;

	}
}
//DELETE FROM `heroes` WHERE `Users_idUsers` and `idHeroes`