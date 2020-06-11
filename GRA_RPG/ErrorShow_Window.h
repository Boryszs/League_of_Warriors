#pragma once
#include "Window_Base.h"
class ErrorShow_Window
{
public:
	ErrorShow_Window();
	~ErrorShow_Window();

	void Start(string err);
private:

	RectangleShape ok;
	Window_Base window;
	Font arial;
	Text erro;

};

