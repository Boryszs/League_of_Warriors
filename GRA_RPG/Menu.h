#pragma once
#include "Button.h"
#include "Window_Base.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Champion.h"
#include "DBcontroler.h"

using namespace std;
using namespace sf;

/// Class Menu represent window Menu  inherit Window_Base.
class Menu: public Window_Base
{
private:
	Champion* champion;
	int idUser;
public:
	/// Object Sprite use to show table.
	Sprite backroundTable;
	/// Object Texture use to load image.
	Texture backgroundTab;

	/// Defalut Constructor Menu.
	Menu();
	/// Constructor Menu.
	/// <param name="String "> - Title window </param>
	/// <param name="int "> - Wifth window </param>
	/// <param name="int "> - Height window </param>
	/// <param name="String "> - Path to backgrand image</param>
	/// <param name="idUser "> - Value  hold in User a database </param>
	Menu(String,int,int,String,int idUser);
	/// Destructor Menu.
	~Menu();
	/// Function start showing a graphic interface.
	void Start();
	/// Object a base window class use to create window.
	Window_Base window;
	/// Values use to keep name widow.
	string title;
	/// Width windows.
	int width;
	/// Height window.
	int height;
	/// Texture use to load backround image.
	Texture background;
	/// Sprite use to showing a background.
	Sprite backroundImage;
	/// Object buttton to create and show button.
	Button buttonStart;
	/// Object buttton to create and show button.
	Button buttonExit;
	/// Object class DBController use to connect a database.
	DBcontroler dbcontroler;
	/// Object use to hold a database get value.
	MYSQL_RES* res;
	/// Object hold a row witch data get with database.
	MYSQL_ROW row;
	/// Value Font to load a font.
	Font arial;
	/// Dynamic value Text to show a chammpion in table .
	Text **Text_Data;

	/// Value to hold a choose.
	int choose;
	/// Value hold count a champion get a database.
	int size;
	/// Object use to check who row table is click.
	RectangleShape *rectangle_choose;
	/// Object use to check if button add is click.
	RectangleShape add_b;
	/// Object use to check if button delete is click.
	RectangleShape delete_b;
};




