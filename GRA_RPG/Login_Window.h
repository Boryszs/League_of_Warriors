#pragma once
#include <SFML/Graphics.hpp>
#include "Window_Base.h"
#include "View_Item.h"
#include "DBcontroler.h"
using namespace sf;

/// Class window support login user.
class Login_Window
{
private:
	int idUser;
public:
	/// Constructor window.
	Login_Window();
	/// Deconstructor window.
	~Login_Window();
	/// Base window class use to create window.
	Window_Base window;
	/// Button to validation login user.
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
	/// Mouse click field to validate the data login.
    RectangleShape rectangle_log;
	/// Mouse click field to enter user login.
    RectangleShape rectangle_user;
	/// Mouse click field to enter user password.
    RectangleShape rectangle_pass;
	/// Mouse click field to go rejestration window.
    RectangleShape rectangle_create;
	/// Flag checking which field is clicked.
	int flaga;
	/// Function start showing window with user creation.
	void Start();

};

