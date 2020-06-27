#pragma once
#include "Window_Base.h"
#include "Champion.h"
#include "View_Item.h"
#include "DBcontroler.h"
#include "Button.h"

/// Class restaurant to representation graphic Window object restaurant inherit Window_Base.
class Restaurant_Window:public Window_Base
{
public:
	/// Variable aria lto load a font.
	Font arial;
	/// Value dyamic 2D array Text use to hold a text.
	Text** Text_Data;
	/// Variable Sprite use to show a table.
	Sprite backroundTable;
	/// Variable Texture use to load a image.
	Texture backgroundTab;
	/// Object use to connect a database.
	DBcontroler dbcontroler;
	/// Object temporary use to hold a row with database value.
	MYSQL_ROW row;
	/// Variable use to hold data get a database.
	MYSQL_RES* res;

	/// Dynamic array use to check who row is click.
	RectangleShape* rectangle_choose;
	/// Value hold a choose .
	int choose;
	/// Variable hold a cout data get with database.
	int size;
	/// Object class Button.
	Button buttonStart;

	/// Constructor Restaurant_Window.
	/// <param name="champ"> - Pointet object Champion </param>
	/// <param name="idUse"> - Value use to hold id user</param>
	Restaurant_Window(Champion* champ,int idUse);
	/// Destructor.
	~Restaurant_Window();
	/// Function start showing graphic interface.
	void Start();
private:
	//bsae window class use to create window
	int idUser;
	Window_Base window;
	Champion* champion;
};

