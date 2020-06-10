#pragma once
#include <SFML/Graphics.hpp>
#include "Window_Base.h"
#include "View_Item.h"

using namespace std;
using namespace sf;
/*
Class use to show graphic city
*/
class Map_Windows: public Window_Base
{
public:
	//constructor
	Map_Windows(String title, int width, int height, String backroundPath);
	Map_Windows();
	//destructor
	~Map_Windows();
	//function start showing
	void Start();
	//set position figure
	void setPosition_figure(int,int);
	//object base class use to create graphic window 
	Window_Base window;
	//object class View_Item use to show some graphics
	View_Item viewItem_key_shop;
	View_Item viewItem_key_arena;
	View_Item viewItem_key_rest;
	View_Item viewItem_figure;
	sf::Clock clock;
	IntRect rectSourceSprite;
};

