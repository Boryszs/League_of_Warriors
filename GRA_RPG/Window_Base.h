#pragma once
#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
using namespace sf;

/// Base class use to make graphic interface.
class Window_Base
{
public:
	/// Constructor Class Window_Base.
	/// <param name="title"> - Title of window</param>
	/// <param name="width"> - Width window</param>
	/// <param name="height"> - Height window</param>
	/// <param name="backroundPath"> - Path to basic background image</param>
	Window_Base(String title, int width, int height, String backroundPath);
	/// Default Constructor Class Window_Base.
	Window_Base();
	/// Destructor Window_Base.
	~Window_Base();
	/// Function to get make window.
	RenderWindow &getWindows();
	/// Basic background image.
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

