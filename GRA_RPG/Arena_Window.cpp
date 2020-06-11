#include "Arena_Window.h"
#include "Map_Windows.h"
#include "Fight.h"
#include "DBcontroler.h"
#include <thread>

Arena_Window::Arena_Window(Champion* champ):window("Arena",950, 950, "Image/mapUi_arena.png"),hydra("Image/m2.png",560,560)
{
	champion = champ;
}

Arena_Window::~Arena_Window() 
{

}

void setText(sf::Text* t1, string s1, sf::Text* t2, string s2)
{
		t1->setString(s1);
		t2->setString(s2);
}

void Arena_Window::Start()
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

	DBcontroler dbc;
	Champion* wsk1 = dbc.getChampion(1);
	Champion* wsk2 = dbc.getChampion(2);
	Fight fight(wsk1, wsk2);

	sf::Thread thread_fight(&Fight::startFigft, &fight);

	thread_fight.launch();
	while (window.getWindows().isOpen())
	{
		setText(&text1, fight.getChamp1(), &text2, fight.getChamp2());

		sf::Event event;
		while (window.getWindows().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.getWindows().close();
		}
	  if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
		     sleep(milliseconds(700));
			 window.getWindows().close();
			 Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png",champion);
			 map_windows.setPosition_figure(80, 805);
			 map_windows.Start();
		}

	  window.getWindows().clear();
	  window.getWindows().draw(window.backroundImage);
	  window.getWindows().draw(hydra.getImage());
	  window.getWindows().draw(text1);
	  window.getWindows().draw(text2);
	  window.getWindows().display();
	}
}