#pragma once
#include <mysql.h>
#include <iostream>
#include "Champion.h"

///  Class responsible for database operation
class DBcontroler
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qstate;

public:
	/// Constructor establishing a connection to the database.
	DBcontroler();
	/// Destructor disconnection to the database.
	~DBcontroler();

	///  Function check the user exists in the database.
	/// <param name="id"> - id user</param>
	/// <returns>true or false</returns>
	bool checkUser(int id);

	/// Function check the user exists in the database.
	/// <param name="login"> - login given by user</param>
	/// <returns>true or false</returns>
	bool checkUser(std::string login);

	/// Update function for data downloaded from player and amending the values in the database.
	/// <param name="champ"> - player's object</param>
	void updateChampion(Champion *champ);

	/// Function adding a new character to the database.
	/// <param name="champ"> - Champion class object with generated basic statistics</param>
	/// <param name="class_hero"> - player's chosen character class</param>
	/// <param name="idUser"> - player's id</param>
	void addChampion(Champion* champ,int class_hero,int idUser);

	/// Function to assign the created champion to the user.
	/// <param name="idUser"> - player's id</param>
	void addHeroes(int idUser);

	/// function removing to player's character.
	/// <param name="idUser"> - player's id</param>
	/// <param name="idChampion"> - player's character id</param>
	void deleteHeroes(int idUser,int idChampion);

	/// function removing to player's character.
	/// <param name="idUser"> - player's id</param>
	void deleteHeroe(int idUser);

	/// Function adding a new user.
	/// <param name="login"> - player's login</param>
	/// <param name="password"> - player's password</param>
	/// <returns>confirm adding new user - true or false</returns>
	bool addUser(std::string login, std::string password);

	/// Function finding user id.
	/// <param name="login"> - user's login</param>
	/// <param name="password"> - user's password</param>
	/// <returns>Row with user's id</returns>
	MYSQL_ROW getUser(std::string login, std::string password);
	
	/// Function finding all player's champions.
	/// <param name="id"> - user's id</param>
	/// <returns>Rows with all player's champions</returns>
	MYSQL_RES* getChampions(int id);

	/// Function finds what class the characters is.
	/// <param name="id"> - champion's id</param>
	/// <returns>Row with id proffesion</returns>
	MYSQL_ROW getProf(int id);

	/// Function creates a new character
	/// <param name="id"> - champion's id</param>
	/// <returns>Pointer to new character</returns>
	Champion* getChampion(int id);

	/// <summary>
	/// Function finding 3 random character different to given id
	/// </summary>
	/// <param name="id"> - character's id</param>
	/// <returns>Rows with champions data</returns>
	MYSQL_RES* randomChampion(int id);
};