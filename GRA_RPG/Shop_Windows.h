#pragma once
#include "Window_Base.h"
#include "Map_Windows.h"

/*
Class shop to representation graphic Window object shop
*/
class Shop_Windows : public Window_Base
{
public:
	//constructor
	Shop_Windows();
	//destructor
	~Shop_Windows();
	//function start showing 
	void Start();
private:
	//bsae window class use to create window
	Window_Base window;
};

