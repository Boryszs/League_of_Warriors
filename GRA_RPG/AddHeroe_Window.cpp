#include "AddHeroe_Window.h"
#include "Menu.h"
#include "DBcontroler.h"
#include "Champion.h"
#include "Archer.h"
#include "Warrior.h"
#include "Wizzard.h"


AddHeroe_Window::AddHeroe_Window(int idUse):window("Login", 273, 311, "Image/add_w.png"),dbcontroler()
{

	idUser = idUse;
	//load arial fonts
	arial.loadFromFile("Fonts/Arial.ttf");

	//recrtangle use to write username
	rectangle_name.setSize(sf::Vector2f(215, 30));
	rectangle_name.setPosition(30, 60);
	//rectangle_name.setFillColor(Color::Cyan);


	//recrtangle use to click button login
	Logo_Button.setColor(Color::Black);
	Logo_Button.setScale(100, 100);
	Logo_Button.setPosition(100, 100);

	//recrtangle use to click button create
	rectangle_add.setSize(sf::Vector2f(170, 30));
	rectangle_add.setPosition(50, 235);
	//rectangle_add.setFillColor(Color::Cyan);

	//Text to show input character in login
	Name.setFillColor(sf::Color::Black);
	Name.setFont(arial);
	Name.setCharacterSize(16);
	Name.setPosition(30, 60);

	rectangle_choose = new RectangleShape[3];
	for (int i = 0; i < 3; i++)
	{
		rectangle_choose[i].setPosition(21, 117 + (i * 37));
		rectangle_choose[i].setSize(sf::Vector2f(32, 25));
		//rectangle_choose[i].setFillColor(Color::Blue);
	}
	flaga = 0;
}
AddHeroe_Window::~AddHeroe_Window()
{

}
void AddHeroe_Window::Start()
{
	while (window.getWindows().isOpen())
	{
		sf::Event event;
		while (window.getWindows().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.getWindows().close();
				Menu menu("Game", 800, 600, "Image/background.png", idUser);
				menu.Start();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (rectangle_add.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					//after click create button
					window.getWindows().close();
					sleep(milliseconds(700));	
					Champion* champ=nullptr;
					cout << idUser;
					if (choose == 0)
						champ = new Archer(0, name, 1, 1, 10.0, 100, 1, 10, 1, 10, 1);
					else if (choose == 1)
						champ = new Warrior(0, name, 1, 1, 10.0, 100, 10, 1, 1, 10, 1);
					else if (choose == 2)
						champ = new Wizzard(0, name, 1, 1, 10.0, 100, 1, 1, 10, 10, 1);
					dbcontroler.addChampion(champ,choose+1,idUser);
					Menu menu("Game", 800, 600, "Image/background.png",idUser);
					menu.Start();
				}
				else if (rectangle_name.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					flaga = 1;
				}
				else
				{
					flaga = 0;
				}

				for (int i = 0; i < 3; i++)
				{
					if (choose != -1 && flaga!=1)
					{
						rectangle_choose[choose].setFillColor(Color::White);
					}
					if (rectangle_choose[i].getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
					{
						rectangle_choose[i].setFillColor(Color::Blue);
						choose = i;
						break;
					}
					else if (rectangle_name.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
					{
						break;
					}
					else
					{
						rectangle_choose[i].setFillColor(Color::White);
						choose = -1;
					}
				}
				cout << choose;

			}

			//input login text
			if (event.type == sf::Event::TextEntered && flaga == 1) {
				if (event.text.unicode < 128) {
					name += static_cast<char>(event.text.unicode);
				}
			}

			//delete character in text username and password
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				if (name.size() > 0 && flaga == 1)
				{
					name.resize(name.size() - 1);
				}
			}

			//set string to text to show in window
			Name.setString(name);


			//draw in window
			window.getWindows().clear();
			window.getWindows().draw(rectangle_name);
			window.getWindows().draw(rectangle_add);
			window.getWindows().draw(window.backroundImage);
			window.getWindows().draw(Name);
			for (int i = 0; i < 3; i++)
			{
				window.getWindows().draw(rectangle_choose[i]);
			}
			window.getWindows().display();
		}

	}
}