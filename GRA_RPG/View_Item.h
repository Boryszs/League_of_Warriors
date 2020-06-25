#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
/*
Class use  to representation  some graphics 
*/
class View_Item
{
public:
	//constructor
	View_Item();
	View_Item(String Path,int x ,int y);
	//destructor
	~View_Item();
	//some values help to representant graphic
	Sprite Image;
	Texture item;
	//function return object to show graphic
	Sprite &getImage();
	void set_Image(String Path, int x, int y);
private:
	//value to represent position graphic
	int x,y;
};

