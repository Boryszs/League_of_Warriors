#pragma once
#include "Window_Base.h"
#include "Champion.h"
#include "View_Item.h"
#include "DBcontroler.h"
#include "Button.h"
/*
Class restaurant to representation graphic Window object restaurant
*/
class Restaurant_Window:public Window_Base
{
public:
	Font arial;
	Text** Text_Data;
	Sprite backroundTable;
	Texture backgroundTab;
	DBcontroler dbcontroler;
	MYSQL_ROW row;
	MYSQL_RES* res;

	RectangleShape* rectangle_choose;
	int choose;
	int size;
	Button buttonStart;

	//consttructor
	Restaurant_Window(Champion* champ,int idUse);
	//destructor
	~Restaurant_Window();
	//function start showing 
	void Start();
private:
	//bsae window class use to create window
	int idUser;
	Window_Base window;
	Champion* champion;
};

