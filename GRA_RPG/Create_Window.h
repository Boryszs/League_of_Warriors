#include "Menu.h"
#include <iostream>
#pragma once

class Create_Window
{
	/*
	Class support create user.
	*/

public:
	//Constructor
	Create_Window();
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

	RectangleShape rectangle_user;
	RectangleShape rectangle_pass;
	RectangleShape rectangle_create;
	//function start showing 
	void Start();
};

