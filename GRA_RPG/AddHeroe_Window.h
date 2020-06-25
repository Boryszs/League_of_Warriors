#pragma once
#include "Window_Base.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "DBcontroler.h"
#include "Login_Window.h"
#include <iostream>

class AddHeroe_Window : public Window_Base
{
public:
	//Constructor
	AddHeroe_Window();
	~AddHeroe_Window();
	

	//base window class use to create window
	Window_Base window;
	Sprite Logo_Button;
	Font arial;

	Text Name;
	DBcontroler dbcontroler;

	string name;
	int profession;

	int flaga;
	int choose;
	RectangleShape rectangle_name;
	RectangleShape rectangle_add;
	RectangleShape* rectangle_choose;
	//function start showing 
	void Start();
};

