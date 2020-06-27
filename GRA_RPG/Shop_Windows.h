#pragma once
#include "Window_Base.h"
#include "Map_Windows.h"
#include "Champion.h"

/// Class shop to representation graphic Window object shop.
class Shop_Windows : public Window_Base
{
public:
	/// Constructor Class Shop_Windows.
	/// <param name="champ"> - character witch enter to window</param>
	/// <param name="idUse"> - user's id</param>
	Shop_Windows(Champion* champ,int idUse);
	/// Destructor Shop_Windows.
	~Shop_Windows();
	/// Function start showing window.
	void Start();
	/// Function checks if the character has enough cash.
	/// <param name="money"> - the money held by character</param>
	/// <returns>true or false</returns>
	bool moneycheck(int money);
private:
	//bsae window class use to create window
	int idUser;
	Window_Base window;
	Champion* champion;
	RectangleShape r_health;
	RectangleShape r_strength;
	RectangleShape r_dexterity;
	RectangleShape r_magic;
	RectangleShape r_defence;
	RectangleShape r_lucky;
	Font arial;
	Text health;
	Text strength;
	Text dexterity;
	Text magic;
	Text defence;
	Text lucky;
	View_Item mouse;
	Text money;
	int count;
	int hei;
};

