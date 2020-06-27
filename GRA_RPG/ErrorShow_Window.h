#pragma once
#include "Window_Base.h"

/// Classe represenr window to show a error messge.
class ErrorShow_Window
{
public:
	/// Constructor object ErrorShow_Window.
	ErrorShow_Window();
	/// Destructor object ErrorShow_Window.
	~ErrorShow_Window();
	/// Function Start to show graphic interface.
	void Start(string err);
private:

	RectangleShape ok;
	Window_Base window;
	Font arial;
	Text erro;

};

