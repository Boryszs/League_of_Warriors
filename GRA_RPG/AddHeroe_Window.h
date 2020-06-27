#pragma once
#include "Window_Base.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "DBcontroler.h"
#include "Login_Window.h"
#include <iostream>

/// Class window support add character to user.
class AddHeroe_Window : public Window_Base
{

private:
	int idUser;
public:
	/// Constructor window.
	/// <param name="idUser">user's id</param>
	AddHeroe_Window(int idUser);
	/// Deconstructor window.
	~AddHeroe_Window();
	

	/// Base window class use to create window.
	Window_Base window;
	/// Button to validation add champion to user.
	Sprite Logo_Button;
	/// Used font.
	Font arial;

	/// Name of new character.
	Text Name;
	/// Data base controller.
	DBcontroler dbcontroler;
	/// Name of new character.
	string name;
	/// Profession id.
	int profession;

	/// Flag to selection class profession.
	int flaga;
	/// Player selection witch class selected.
	int choose;
	/// Mouse click field to enter user name character.
	RectangleShape rectangle_name;
	/// Mouse click field to validate the data.
	RectangleShape rectangle_add;
	/// Mouse click field to check proffesion of character.
	RectangleShape* rectangle_choose;

	/// Function start showing window with user creation new character.
	void Start();
};

