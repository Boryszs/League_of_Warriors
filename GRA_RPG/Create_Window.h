#include "Menu.h"
#include <iostream>
#pragma once

class Create_Window
{
	/*
	Class support create user.
	*/
private:
	int idUser;

public:
	//Constructor
	Create_Window(int idUse);
	//Deconstructor
	~Create_Window();
	//base window class use to create window
	Window_Base window;
	Sprite Logo_Button;
	Font arial;

	Text Login;
	Text Password;

	string login;
	string password;

	int flaga;

	DBcontroler dbcontroler;

	RectangleShape rectangle_user;
	RectangleShape rectangle_pass;
	RectangleShape rectangle_create;
	//function start showing 
	void Start();
};

