#include "Shop_Windows.h"
#include "Champion.h"
#include <string>

Shop_Windows::Shop_Windows(Champion* champ,int idUse):window("Shop", 950, 950, "Image/mapUi_shop.png"),mouse("Image/mysz.png", 200, 790)
{
	hei = 1;
	champion = champ;
	idUser = idUse;
	//recrtangle use 
	r_health.setSize(sf::Vector2f(36, 36));
	r_health.setPosition(97, 308);
	r_health.setFillColor(Color::Cyan);

	r_strength.setSize(sf::Vector2f(36, 36));
	r_strength.setPosition(97, 372);
	r_strength.setFillColor(Color::Cyan);

	r_dexterity.setSize(sf::Vector2f(36, 36));
	r_dexterity.setPosition(97, 430);
	r_dexterity.setFillColor(Color::Cyan);

	r_magic.setSize(sf::Vector2f(36, 36));
	r_magic.setPosition(97, 492);
	r_magic.setFillColor(Color::Cyan);

	r_defence.setSize(sf::Vector2f(36, 36));
	r_defence.setPosition(97, 553);
	r_defence.setFillColor(Color::Cyan);

	r_lucky.setSize(sf::Vector2f(36, 36));
	r_lucky.setPosition(97, 614);
	r_lucky.setFillColor(Color::Cyan);

	arial.loadFromFile("Fonts/Arial.ttf");

	//Text 
	health.setFillColor(Color(255,0,0));
	health.setFont(arial);
	health.setCharacterSize(24);
	health.setPosition(35, 340);

	strength.setFillColor(Color(255, 0, 0));
	strength.setFont(arial);
	strength.setCharacterSize(24);
	strength.setPosition(35, 400);


	dexterity.setFillColor(Color(255, 0, 0));
	dexterity.setFont(arial);
	dexterity.setCharacterSize(24);
	dexterity.setPosition(35, 460);


	magic.setFillColor(Color(255, 0, 0));
	magic.setFont(arial);
	magic.setCharacterSize(24);
	magic.setPosition(35, 520);


	defence.setFillColor(Color(255, 0, 0));
	defence.setFont(arial);
	defence.setCharacterSize(24);
	defence.setPosition(35, 580);


	lucky.setFillColor(Color(255, 0, 0));
	lucky.setFont(arial);
	lucky.setCharacterSize(24);
	lucky.setPosition(35, 640);

	//
	money.setFillColor(Color(255, 0, 0));
	money.setFont(arial);
	money.setCharacterSize(24);
	money.setPosition(45, 200);
	count = 0;

}
Shop_Windows::~Shop_Windows()
{

}

bool Shop_Windows::moneycheck(int money)
{
	if ((money - 5)>=0)
	{
		return true;
	}
	return false;
}

void Shop_Windows::Start()
{
	while (window.getWindows().isOpen())
	{
		sleep(milliseconds(5));
		sf::Event event;
		while (window.getWindows().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				sleep(milliseconds(700));
				window.getWindows().close();
				Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png", champion,idUser);
				map_windows.setPosition_figure(870, 220);
				map_windows.Start();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (r_health.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (moneycheck(champion->getMoney()))
					{
						champion->addMoney(-5);
						champion->addHealth(1);
					}
				}
				else if (r_strength.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (moneycheck(champion->getMoney()))
					{
						champion->addMoney(-5);
						champion->addStrength(1);
					}
				}
				else if (r_dexterity.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (moneycheck(champion->getMoney()))
					{
						champion->addMoney(-5);
						champion->addDexterity(1);
					}
				}
				else if (r_magic.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (moneycheck(champion->getMoney()))
					{
						champion->addMoney(-5);
						champion->addMagic(1);
					}
				}
				else if (r_defence.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (moneycheck(champion->getMoney()))
					{
						champion->addMoney(-5);
						champion->addDefence(1);
					}
				}
				else if (r_lucky.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (moneycheck(champion->getMoney()))
					{
						champion->addMoney(-5);
						champion->addMoney(1);
					}
				}
			}


			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				sleep(milliseconds(700));
				window.getWindows().close();
				Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png", champion,idUser);
				map_windows.setPosition_figure(870, 220);
				map_windows.Start();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (mouse.getImage().getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					count++;
					sleep(milliseconds(15));
					mouse.getImage().setPosition(200, 790);
				}
			}
		}

		
		if (mouse.getImage().getPosition().x == 840)
		{
			mouse.getImage().setPosition(200, 790);
		}

		if (mouse.getImage().getPosition().y == 830)
		{
			hei = -1;
		}
		else if (mouse.getImage().getPosition().y == 750)
		{
			hei = 1;
		}
		
		mouse.getImage().move(2 , hei);
		//cout << mouse.getImage().getPosition().y<<"\n";

		if (count == 10)
		{
			count = 0;
			champion->addMoney(1);
		}

		//set values to view
		health.setString(to_string(champion->getHealth()));
		strength.setString(to_string(champion->getStrength()));
		dexterity.setString(to_string(champion->getDexterity()));
		magic.setString(to_string(champion->getMagic()));
		defence.setString(to_string(champion->getDefence()));
		lucky.setString(to_string(champion->getLuck()));
		money.setString(to_string(champion->getMoney()));

		window.getWindows().clear();
		window.getWindows().draw(r_health);
		window.getWindows().draw(r_strength);
		window.getWindows().draw(r_dexterity);
		window.getWindows().draw(r_magic);
		window.getWindows().draw(r_defence);
		window.getWindows().draw(r_lucky);
		window.getWindows().draw(window.backroundImage);
		window.getWindows().draw(health);
		window.getWindows().draw(strength);
		window.getWindows().draw(dexterity);
		window.getWindows().draw(magic);
		window.getWindows().draw(defence);
		window.getWindows().draw(lucky);
		window.getWindows().draw(mouse.getImage());
		window.getWindows().draw(money);
		window.getWindows().display();
	}
}