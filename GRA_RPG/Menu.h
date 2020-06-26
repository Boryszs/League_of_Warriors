#pragma once
#include "Button.h"
#include "Window_Base.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Champion.h"
#include "DBcontroler.h"

using namespace std;
using namespace sf;
/*
Class Menu 
*/
class Menu: public Window_Base
{
private:
	Champion* champion;
public:

	Sprite backroundTable;
	Texture backgroundTab;

	//constructor
	Menu();
	Menu(String,int,int,String);
	//destructor
	~Menu();
	//function start showing 
	void Start();
	//bsae window class use to create window
	Window_Base window;
	//CircleShape shape;
	//values use to keep name widow
	string title;
	//width and height window
	int width, height;
	//Texture and sprite use to show backround
	Texture background;
	Sprite backroundImage;
	//object buttton to create and show button
	Button buttonStart;
	Button buttonExit;
	DBcontroler dbcontroler;
	MYSQL_RES* res;
	MYSQL_ROW row;

	Font arial;
	Text **Text_Data;

	int choose;
	int size;
	RectangleShape *rectangle_choose;
	RectangleShape add_b;
};




