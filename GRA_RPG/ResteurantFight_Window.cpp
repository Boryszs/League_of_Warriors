#include "RestaurantFight_Window.h"
#include "Map_Windows.h"
#include "Fight.h"
#include "DBcontroler.h"
#include <thread>
#include "Restaurant_Window.h"

//
RestaurantFight_Window::RestaurantFight_Window(Champion* champ, Champion* opon, int id) : window("Restaurant", 950, 950, "Image/mapUi_res.png"), fight(champ->clone(), opon->clone()), dbc()
{
    champion = champ;
    oponnent = opon;
    idUser = id;
}

RestaurantFight_Window::~RestaurantFight_Window()
{
    delete oponnent;
}

void setText1(sf::Text* t1, string s1, sf::Text* t2, string s2)
{
    t1->setString(s1);
    t2->setString(s2);
}

void RestaurantFight_Window::Start()
{
    sf::Font font;
    font.loadFromFile("Fonts/Arial.ttf");
    sf::Text text1;
    text1.setFont(font);
    text1.setString("Hello");
    text1.setCharacterSize(32);
    text1.setFillColor(sf::Color::Red);
    text1.setStyle(sf::Text::Bold);
    text1.setPosition(sf::Vector2f(150, 30));
    sf::Text text2 = text1;
    text2.setPosition(650, 30);

    sf::Thread thread_fight(&Fight::startFigft, &fight);

    thread_fight.launch();
    while (window.getWindows().isOpen())
    {
        sleep(milliseconds(5));
        setText1(&text1, champion->getName() + " : " + fight.getChamp1(), &text2, oponnent->getName() + " : " + fight.getChamp2());

        if (std::stoi(fight.getChamp2()) <= 0 && std::stoi(fight.getChamp1()) >= 0)
        {
            text2.setString("WIN!");
            champion->addMoney(5);
            champion->addExperience(champion->getLevel() * 10);
            oponnent->takeMoney(5);
            dbc.updateChampion(champion);
            dbc.updateChampion(oponnent);
            window.getWindows().clear();
            window.getWindows().draw(window.backroundImage);
            window.getWindows().draw(text1);
            window.getWindows().draw(text2);
            window.getWindows().display();
            sleep(milliseconds(5000));
            window.getWindows().close();
            Restaurant_Window aren_window(champion, idUser);
            aren_window.Start();
        }
        if (std::stoi(fight.getChamp1()) <= 0 && std::stoi(fight.getChamp2()) >= 0)
        {
            text2.setString("LOSE!");
            oponnent->addMoney(5);
            oponnent->addExperience(champion->getLevel() * 10);
            champion->takeMoney(5);
            dbc.updateChampion(champion);
            dbc.updateChampion(oponnent);
            window.getWindows().clear();
            window.getWindows().draw(window.backroundImage);
            window.getWindows().draw(text1);
            window.getWindows().draw(text2);
            window.getWindows().display();
            sleep(milliseconds(5000));
            window.getWindows().close();
            Restaurant_Window aren_window(champion, idUser);
            aren_window.Start();
        }
        if (std::stoi(fight.getChamp1()) <= 0 && std::stoi(fight.getChamp2()) <= 0)
        {
            text2.setString("DRAW!");
            oponnent->addExperience(champion->getLevel() * 10);
            champion->addExperience(champion->getLevel() * 10);
            dbc.updateChampion(champion);
            dbc.updateChampion(oponnent);
            window.getWindows().clear();
            window.getWindows().draw(window.backroundImage);
            window.getWindows().draw(text1);
            window.getWindows().draw(text2);
            window.getWindows().display();
            sleep(milliseconds(5000));
            window.getWindows().close();
            Restaurant_Window aren_window(champion, idUser);
            aren_window.Start();
        }

        sf::Event event;
        while (window.getWindows().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                thread_fight.terminate();
                sleep(milliseconds(700));
                window.getWindows().close();
                Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png", champion, idUser);
                map_windows.setPosition_figure(840, 660);
                map_windows.Start();
            }

        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            thread_fight.terminate();
            sleep(milliseconds(700));
            window.getWindows().close();
            Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png", champion, idUser);
            map_windows.setPosition_figure(840, 660);
            map_windows.Start();
        }

        window.getWindows().clear();
        window.getWindows().draw(window.backroundImage);
        window.getWindows().draw(text1);
        window.getWindows().draw(text2);
        window.getWindows().display();
    }
}