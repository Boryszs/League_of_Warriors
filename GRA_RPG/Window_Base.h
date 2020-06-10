#pragma once
#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
using namespace sf;

/*
Base class use to make graphic intefejs
*/
class Window_Base
{
public:
	//constructor
	Window_Base(String title, int width, int height, String backroundPath);
	Window_Base();
	//destructor
	~Window_Base();
	//function to get make window 
	RenderWindow &getWindows();
	Sprite backroundImage;
protected:
	//value help to representation backround
	Texture background;
	//object use to create window base a librare sfml
	RenderWindow window;
	//title window
	string title;
	//value width and height window
	int width, height;
	
	


};

