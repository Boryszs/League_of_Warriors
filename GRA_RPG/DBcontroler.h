#pragma once
#include <mysql.h>
#include <iostream>
#include "Champion.h"

class DBcontroler
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qstate;
	

public:
	DBcontroler();
	//~DBcontroler();

	// funkcja sprawdzaj¹ca czy dany u¿ytkownik istnieje
	bool checkUser(int id);
	bool checkUser(std::string login);
	//function update value champion in database 
	void updateChampion(Champion *champ);
	//function add champion to database 
	void addChampion(Champion* champ,int class_hero,int idUser);
	//Trgigger 
	void addHeroes(int idUser);
	//Delete Heroes 
	void deleteHeroes(int idUser,int idChampion);
	//delete heroe
	void deleteHeroe(int idUser);
	// funkcja dodaj¹ca usera
	bool addUser(std::string login, std::string password);
	// funkcja zwracaj¹ca idUsers na podstawie poprawnych danych (login i passwd) z bazy
	MYSQL_ROW getUser(std::string login, std::string password);
	// funkcja zwracaj¹ca idHeroes (iloœæ posiadanych postaci przez u¿ytkownika przy tworzeniu trzeba sprawdzaæ LIMIT 3 !!!)
	MYSQL_RES* getChampions(int id);
	//Get professions
	MYSQL_ROW getProf(int id);
	// funkcja zwracaj¹ca wskaŸnik na postaæ o danym idHeroes
	Champion* getChampion(int id);
	// funckja dodaj¹ca postaæ na podstawie podanej nazyw



	MYSQL* getConn() { return conn; }
};