#pragma once
#include <SFML/Graphics.hpp>
#include "Window_Base.h"
#include "View_Item.h"
#include "Champion.h"
#include "DBcontroler.h"

using namespace std;
using namespace sf;

/// Class use to show graphic city and supporting all activities Inherits a Window_Base.
class Map_Windows: public Window_Base
{
private:
	Champion* champion;
	int idUser;
public:
	/// Constructor Class Map_Windows.
	/// <param name="title"> - Title a windows </param>
	/// <param name="width"> - Width window</param>
	/// <param name="height"> - Height window</param>
	/// <param name="champ"> -Object type Champion use to refresh value </param>
	/// <param name="idUser"> - Id User with a database</param>
	Map_Windows(String title, int width, int height, String backroundPath, Champion* champ, int idUser);
	/// Default constructor Class Map_Windows.
	Map_Windows();
	/// Destructor Map_Windows.
	~Map_Windows();
	/// Function start showing a graphic interface.
	void Start();
	/// Function to set position character after back to a other activity.
	void setPosition_figure(int,int);
	/// Object base class use to create graphic window interface.
	Window_Base window;
	/// Object class View_Item use to show some graphics image.
	View_Item viewItem_key_shop;
	/// Object class View_Item use to show some graphics image.
	View_Item viewItem_key_arena;
	/// Object class View_Item use to show some graphics image.
	View_Item viewItem_key_rest;
	/// Object class View_Item use to show some graphics image.
	View_Item viewItem_figure;
	/// Object helping to create animations.
	sf::Clock clock;
	/// Object helping to create animations.
	IntRect rectSourceSprite;
	/// Object use to connect a database.
	DBcontroler dbcontroler;

	///Object use to collision on a some object.
	RectangleShape col_l_u_1;
	///Object use to collision on a some object.
	RectangleShape col_l_u_2;

	///Object use to collision on a some object.
	RectangleShape col_r_u_1;
	///Object use to collision on a some object.
	RectangleShape col_r_u_2;

	///Object use to collision on a some object.
	RectangleShape col_l_d_1;
	///Object use to collision on a some object.
	RectangleShape col_l_d_2;

	///Object use to collision on a some object.
	RectangleShape col_r_d_1;
	///Object use to collision on a some object.
	RectangleShape col_r_d_2;
	///Object use to collision on a some object.
	RectangleShape col_r_d_3;
};

