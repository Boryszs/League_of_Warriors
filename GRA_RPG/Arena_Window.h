#pragma once
#include "Window_Base.h"
#include "View_Item.h"
#include "Champion.h"

class Arena_Window : public Window_Base
{
/*
Class arena to representation graphic Window object Arena
*/

public:
	//constructor
	Arena_Window(Champion* champ);
	//destructor
	~Arena_Window();
	//function start showing 
	void Start();
	RectangleShape getClickHeal() { return click_heal; }
	void randMonster();
private:

	Champion* champion;
	//base window class use to create window
	Window_Base window;
	View_Item hydra;
	View_Item heal;
	RectangleShape click_heal;
};

