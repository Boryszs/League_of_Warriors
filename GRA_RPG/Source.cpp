#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Login_Window.h"
#include "ThrowLoad.cpp"
#include <iostream>


int main()
{
	try
	{
		Login_Window login_window;
		login_window.Start();
	}
	catch (MyException & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}