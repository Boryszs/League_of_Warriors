#include "Arena_Window.h"
#include "Map_Windows.h"
#include "Fight.h"
#include "DBcontroler.h"
#include <thread>
#include "Monster.h"
#include <random>

Arena_Window::Arena_Window(Champion* champ):window("Arena",950, 950, "Image/mapUi_arena.png"), heal("Image/heal.png", 130, 620)
{
	champion = champ;
	click_heal.setSize(sf::Vector2f(200, 200));
	click_heal.setPosition(120, 600);
	randMonster();
}

Arena_Window::~Arena_Window() 
{

}

void Arena_Window::randMonster()
{
	random_device dev;
	mt19937_64 rng(dev());
	uniform_int_distribution<> dist(1, 5);
	int val = dist(rng);

	if (val == 1)
		hydra.set_Image("Image/m1.png", 560, 560);
	else if (val == 2)
		hydra.set_Image("Image/m2.png", 560, 560);
	else if (val == 3)
		hydra.set_Image("Image/m3.png", 560, 560);
	else if (val == 4)
		hydra.set_Image("Image/m4.png", 560, 560);
	else if (val == 5)
		hydra.set_Image("Image/m5.png", 560, 560);
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
	Champion* monster = new Monster(champion);

	Fight fight(champion, monster);

	sf::Thread thread_fight(&Fight::startFigft, &fight);

	thread_fight.launch();
	while (window.getWindows().isOpen())
	{
		sleep(milliseconds(5));
		setText(&text1, champion->getName() + " : " + fight.getChamp1(), &text2, monster->getName() + " : " + fight.getChamp2());

		if (std::stoi(fight.getChamp2()) <= 0)
		{
			thread_fight.wait();
			delete monster;
			champion->addMoney(1);
			champion->addExperience(champion->getLevel() * 10);
			dbc.updateChampion(champion);
			randMonster();
			Arena_Window::Start();
		}

		sf::Event event;
		while (window.getWindows().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				thread_fight.terminate();
				{
					sleep(milliseconds(700));
					window.getWindows().close();
					Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png", champion);
					map_windows.setPosition_figure(80, 805);
					map_windows.Start();
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (getClickHeal().getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					fight.heal(champion);
				}
			}
		}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		thread_fight.terminate();
		sleep(milliseconds(700));
		window.getWindows().close();
		Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png",champion);
		map_windows.setPosition_figure(80, 805);
		map_windows.Start();
	}

	window.getWindows().clear();
	window.getWindows().draw(getClickHeal());
	window.getWindows().draw(window.backroundImage);
	window.getWindows().draw(text1);
	window.getWindows().draw(text2);
	window.getWindows().draw(heal.getImage());
	window.getWindows().draw(hydra.getImage());
	window.getWindows().display();
	}
}