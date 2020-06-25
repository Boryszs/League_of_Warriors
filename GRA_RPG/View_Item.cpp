#include "View_Item.h"
#include <SFML/Graphics.hpp>
#include "ThrowLoad.cpp"

View_Item::~View_Item()
{

}
View_Item::View_Item()
{

}
View_Item::View_Item(String Path,int x,int y)
{
	;
	if (!item.loadFromFile(Path))
	{
		throw MyException("Error module load");
	}
	Image.setTexture(item);
	this->x = x;
	this->y = y;
	Image.setPosition(x, y);
}

void View_Item::set_Image(String Path, int x, int y)
{
	if (!item.loadFromFile(Path))
	{
		throw MyException("Error module load");
	}
	Image.setTexture(item);
	this->x = x;
	this->y = y;
	Image.setPosition(x, y);
}

Sprite &View_Item::getImage()
{
	return Image;
}