#pragma once
#include "Window_Base.h"
#include "Map_Windows.h"
#include "Champion.h"

/*
Class shop to representation graphic Window object shop
*/
class Shop_Windows : public Window_Base
{
public:
	//constructor
	Shop_Windows(Champion* champ);
	//destructor
	~Shop_Windows();
	//function start showing 
	void Start();

	bool moneycheck(int);
private:
	//bsae window class use to create window
	Window_Base window;
	Champion* champion;
	RectangleShape r_health;
	RectangleShape r_strength;
	RectangleShape r_dexterity;
	RectangleShape r_magic;
	RectangleShape r_defence;
	RectangleShape r_lucky;
	Font arial;
	Text health;
	Text strength;
	Text dexterity;
	Text magic;
	Text defence;
	Text lucky;
	View_Item mouse;
	Text money;
	int count;
	int hei;
};

