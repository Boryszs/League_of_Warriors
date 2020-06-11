#include "Window_Base.h"
#include "ThrowLoad.cpp"
#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
using namespace sf;

Window_Base::Window_Base() :window(), background()
{

}

Window_Base::~Window_Base()
{

}

Window_Base::Window_Base(String title, int width, int height, String backroundPath):window()
{
	window.create(sf::VideoMode(width, height), title);
	if (!background.loadFromFile(backroundPath))
	{
		throw MyException("Error module load");
	}
	backroundImage.setTexture(background);
}
RenderWindow &Window_Base::getWindows()
{
	return window;
}



