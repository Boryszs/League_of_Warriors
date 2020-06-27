#pragma once
#include "Window_Base.h"
#include "Champion.h"
#include "View_Item.h"
#include "Fight.h"
#include "DBcontroler.h"

/// Class to representation graphic Window object Fight betwen players.
class RestaurantFight_Window : public Window_Base
{
public:
    /// Constructor RestaurantFight_Window
    /// <param name="champ"> - Player's character</param>
    /// <param name="opon"> - Selected opponent</param>
    /// <param name="id"> - User's id</param>
    RestaurantFight_Window(Champion* champ, Champion* opon, int id);
    /// Destructor Class RestaurantFight_Window
    ~RestaurantFight_Window();
    /// Function start showing RestaurantFight_Window and fight between players.
    void Start();
private:
    //bsae window class use to create window
    Window_Base window;
    Champion* champion;
    Champion* oponnent;
    Fight fight;
    DBcontroler dbc;
    int idUser;
};