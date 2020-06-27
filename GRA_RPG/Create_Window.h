#include "Menu.h"
#include <iostream>
#pragma once

/// Class window support create user.
class Create_Window
{
private:
	int idUser;

public:
	/// Constructor window.
	/// <param name="idUse">user's id</param>
	Create_Window(int idUse);
	/// Deconstructor window.
	~Create_Window();
	/// Base window class use to create window.
	Window_Base window;
	/// Button to validation adding user.
	Sprite Logo_Button;
	/// Used font.
	Font arial;

	/// Display entered login.
	Text Login;
	/// Display entered password.
	Text Password;

	/// Entered login.
	string login;
	/// Entered password.
	string password;

	/// Data base controller.
	DBcontroler dbcontroler;

	/// Mouse click field to enter user login.
	RectangleShape rectangle_user;
	/// Mouse click field to enter user password.
	RectangleShape rectangle_pass;
	/// Mouse click field to validate the data.
	RectangleShape rectangle_create;
	/// Flag checking which field is clicked.
	int flaga;

	/// Function start showing window with user creation.
	void Start();
};

