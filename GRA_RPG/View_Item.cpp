#include "View_Item.h"
#include <SFML/Graphics.hpp>
View_Item::~View_Item()
{

}
View_Item::View_Item()
{

}
View_Item::View_Item(String Path,int x,int y)
{
	item.loadFromFile(Path);
	Image.setTexture(item);
	this->x = x;
	this->y = y;
	Image.setPosition(x, y);
}

Sprite &View_Item::getImage()
{
	return Image;
}