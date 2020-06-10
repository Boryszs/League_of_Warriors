#pragma once
#include "Window_Base.h"
#include "View_Item.h"
class Arena_Window : public Window_Base
{
/*
Class arena to representation graphic Window object Arena
*/

public:
	//constructor
	Arena_Window();
	//destructor
	~Arena_Window();
	//function start showing 
	void Start();
private:
	
	//base window class use to create window
	Window_Base window;
	View_Item hydra;
};

