#include "Login_Window.h"
#include "Menu.h"
#include "Create_Window.h"
#include <iostream>
using namespace std;
using namespace  sf;
Login_Window::Login_Window() :window("Login", 273, 311,"Image/log_w.png")

{
	//load arial fonts
	arial.loadFromFile("Fonts/Arial.ttf");
	rectangle_log.setSize(sf::Vector2f(170, 30));
	rectangle_log.setPosition(50, 160);

	//recrtangle use to write username
    rectangle_user.setSize(sf::Vector2f(215, 30));
	rectangle_user.setPosition(30, 60);
	//rectangle_user.setFillColor(Color::Cyan);

	//recrtangle use to write password
	rectangle_pass.setSize(sf::Vector2f(215, 30));
	rectangle_pass.setPosition(30, 105);
	//rectangle_pass.setFillColor(Color::Green);

	//recrtangle use to click button login
	Logo_Button.setColor(Color::Black);
	Logo_Button.setScale(100, 100);
	Logo_Button.setPosition(100, 100);

	//recrtangle use to click button create
	rectangle_create.setSize(sf::Vector2f(170, 30));
	rectangle_create.setPosition(50, 215);
	//rectangle_create.setFillColor(Color::Cyan);

	//Text to show input character in login
	Login.setFillColor(sf::Color::Black);
	Login.setFont(arial);
	Login.setCharacterSize(16);
	Login.setPosition(30, 60);

	//Text to show input character in password
	Password.setFillColor(sf::Color::Black);
	Password.setFont(arial);
	Password.setCharacterSize(16);
	Password.setPosition(30, 105);

	flaga = 0;
}

Login_Window::~Login_Window()
{

}

void Login_Window::Start()
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
				//check when input text who box 
				if (rectangle_log.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					window.getWindows().close();
					Menu menu("Game", 800, 600, "Image/background.png");
					menu.Start();
				}
				if (rectangle_create.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					window.getWindows().close();
					Create_Window create_window;
					create_window.Start();
				}
				else if (rectangle_user.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					flaga = 1;
				}
				else if (rectangle_pass.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					flaga = 2;
				}
				else
				{
					flaga = 0;
				}
				
			}

			//input login text
			if (event.type == sf::Event::TextEntered && flaga == 1) {
				if (event.text.unicode < 128) {
					login += static_cast<char>(event.text.unicode);
				}
			}

			//input password text
			if (event.type == sf::Event::TextEntered && flaga == 2) {
				if (event.text.unicode < 128) {
					password += static_cast<char>(event.text.unicode);
				}
			}

			//delete character in text username and password
			if (event.key.code == sf::Keyboard::BackSpace) {
				if (login.size() > 0 && flaga == 1)
				{
					login.resize(login.size() - 1);
				}
				if (password.size() > 0 && flaga == 2)
				{
					password.resize(password.size() - 1);
				}
			}

			//set string to text to show in window
			Login.setString(login);
			Password.setString(password);


			//draw in window
			window.getWindows().clear();
			window.getWindows().draw(rectangle_log);
			window.getWindows().draw(rectangle_user);
			window.getWindows().draw(rectangle_pass);
			window.getWindows().draw(rectangle_create);
			window.getWindows().draw(window.backroundImage);
			window.getWindows().draw(Login);
			window.getWindows().draw(Password);
			window.getWindows().display();
		}

	}
}