#pragma once
#include <SFML/Graphics.hpp>
#include "Window_Base.h"
#include "View_Item.h"
#include "DBcontroler.h"
using namespace sf;

class Login_Window
{

	/*
	Class support login.
	*/
	private:
	int idUser;
	public:
	//Constructor
	Login_Window();
	//Deconstructor
	~Login_Window();
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
    RectangleShape rectangle_log;
    RectangleShape rectangle_user;
    RectangleShape rectangle_pass;
    RectangleShape rectangle_create;
	//function start showing 
	void Start();

};

