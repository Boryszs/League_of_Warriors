#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Login_Window.h"
#include "ThrowLoad.cpp"
#include <iostream>
#include "Window_Base.h"
#include "ErrorShow_Window.h"


int main()
{
	FreeConsole();
	try
	{
		
		Login_Window login_window;
		login_window.Start();
	
	}
	catch (MyException &e)
	{
		//std::cout << e.what() << std::endl;

		ErrorShow_Window error;
		error.Start(e.what());

	}
	return 0;
}