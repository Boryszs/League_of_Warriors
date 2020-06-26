#pragma once
#include "Window_Base.h"
#include "Champion.h"
#include "View_Item.h"
#include "Fight.h"
#include "DBcontroler.h"

//
class RestaurantFight_Window : public Window_Base
{
public:
    //consttructor
    RestaurantFight_Window(Champion* champ, Champion* opon, int id);
    //destructor
    ~RestaurantFight_Window();
    //function start showing
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