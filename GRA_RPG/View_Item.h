#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

/// Class use to representation some graphics.
class View_Item
{
public:
	/// Default constructor Class View_Item.
	View_Item();
	/// Constructor Class View_Item.
	/// <param name="Path"> - Path to image</param>
	/// <param name="x"> - Width position</param>
	/// <param name="y"> - Height position</param>
	View_Item(String Path,int x ,int y);
	/// Default constructor Class View_Item.
	~View_Item();
	/// Image as Sprite.
	Sprite Image;
	/// Image as Texture.
	Texture item;
	/// Function return object to show graphic
	Sprite &getImage();
	///  Function to set new image.
	/// <param name="Path"> - Path to new image</param>
	/// <param name="x"> - Width position</param>
	/// <param name="y"> - Height position</param>
	void set_Image(String Path, int x, int y);
private:
	// value to represent position graphic
	int x,y;
};

