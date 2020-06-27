#pragma once
#include "Window_Base.h"
#include "View_Item.h"
#include "Champion.h"

/// Class arena to representation graphic Window object Arena
class Arena_Window : public Window_Base
{
public:
	/// Constructor Arena_Window
	/// <param name="Champ"> - Object type Champion </param>
	/// <param name="idUse"> - Parameter type int to storage id User </param>
	Arena_Window(Champion* champ,int idUse);

	/// Destructor Class Arena_Windows
	~Arena_Window();

	/// Function Start to show graphic interface
	void Start();

	/// Function return object type RectangleShape to show some graphics
	/// <param name="Champ"> - Object type Champion </param>
	/// <param name="idUse"> - Parameter type int to storage id User </param>
	/// <returns>Object type RectangleShape</returns>
	RectangleShape getClickHeal() { return click_heal; }

	/// Function use to random monsters.
	void randMonster();
private:
	int idUser;
	Champion* champion;
	Window_Base window;
	View_Item hydra;
	View_Item heal;
	RectangleShape click_heal;
	
};

