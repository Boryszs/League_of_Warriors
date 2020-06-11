#include "ErrorShow_Window.h"

ErrorShow_Window::ErrorShow_Window():window("error",366,168,"Image/error.png")
{
	ok.setSize(sf::Vector2f(80, 30));
	ok.setPosition(270, 125);
	ok.setFillColor(Color::Yellow);
    
	arial.loadFromFile("Fonts/Arial.ttf");

	erro.setStyle(sf::Text::Bold);
	erro.setFillColor(Color(0, 0, 0));
	erro.setFont(arial);
	erro.setCharacterSize(24);
	erro.setPosition(72, 80);
}
ErrorShow_Window::~ErrorShow_Window()
{
	
}

void ErrorShow_Window::Start(string err)
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
				if (ok.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					window.getWindows().close();
				}
			}
			erro.setString(err);
			window.getWindows().clear();
			window.getWindows().draw(ok);
			window.getWindows().draw(window.backroundImage);
			window.getWindows().draw(erro);
			window.getWindows().display();
		}
	

	}
}