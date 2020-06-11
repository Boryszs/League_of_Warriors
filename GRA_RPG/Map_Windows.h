#pragma once
#include <SFML/Graphics.hpp>
#include "Window_Base.h"
#include "View_Item.h"
#include "Champion.h"
#include "DBcontroler.h"

using namespace std;
using namespace sf;
/*
Class use to show graphic city
*/
class Map_Windows: public Window_Base
{
private:
	Champion* champion;

public:
	//constructor
	Map_Windows(String title, int width, int height, String backroundPath, Champion* champ);
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
	DBcontroler dbcontroler;
	RectangleShape col_l_u_1;
	RectangleShape col_l_u_2;

	RectangleShape col_r_u_1;
	RectangleShape col_r_u_2;


	RectangleShape col_l_d_1;
	RectangleShape col_l_d_2;

	RectangleShape col_r_d_1;
	RectangleShape col_r_d_2;

	RectangleShape col_r_d_3;
};

