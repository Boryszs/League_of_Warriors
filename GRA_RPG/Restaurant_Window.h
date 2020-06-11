#pragma once
#include "Window_Base.h"
#include "Champion.h"
/*
Class restaurant to representation graphic Window object restaurant
*/
class Restaurant_Window:public Window_Base
{
public:
	//consttructor
	Restaurant_Window(Champion* champ);
	//destructor
	~Restaurant_Window();
	//function start showing 
	void Start();
private:
	//bsae window class use to create window
	Window_Base window;
	Champion* champion;
};

