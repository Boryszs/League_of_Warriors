#include "Menu.h"
#include "Map_Windows.h"
#include <SFML/Graphics.hpp>

Menu::~Menu()
{

}

Menu::Menu()
{
	//window.(sf::VideoMode(800, 600), "Window");
	//this->shape.setRadius(100);
}

Menu::Menu(String title,int width,int height,String backroundPath, Champion* champ):buttonStart(),buttonExit(),window(title,width,height,backroundPath)
{
	//window.create(sf::VideoMode(width, height), title);
	//this->shape.setRadius(100);
	this->width = width;
	this->height = height;
	background.loadFromFile(backroundPath);
	backroundImage.setTexture(background);
	buttonStart.setButton("Rozpocznij", 200, 50, Color::Black, 300, 250,340,260);
	buttonExit.setButton("Zakoncz", 200, 50, Color::Black, 300, 350,350, 360);
	champion = champ;
}

void Menu::Start()
{

	while (window.getWindows().isOpen())
	{
		sf::Event event;
		while (window.getWindows().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.getWindows().close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (buttonStart.getButton().getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					window.getWindows().close();
					Map_Windows map_windows("Gra",950,950,"Image/mapo.png",champion);
					map_windows.Start();
				}

				if (buttonExit.getButton().getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					window.getWindows().close();
				}
			}
			window.getWindows().clear();
			window.getWindows().draw(backroundImage);
			window.getWindows().draw(buttonStart.getButton());
			window.getWindows().draw(buttonStart.getText());
			window.getWindows().draw(buttonExit.getButton());
			window.getWindows().draw(buttonExit.getText());
			window.getWindows().display();
		}

	}
}