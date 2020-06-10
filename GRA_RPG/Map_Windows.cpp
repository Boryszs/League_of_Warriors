#include "Map_Windows.h"
#include <iostream>
#include "Menu.h"
#include "Arena_Window.h"
#include "Restaurant_Window.h"
#include "Shop_Windows.h"


using namespace std;

Map_Windows::~Map_Windows()
{

}

Map_Windows::Map_Windows():window()
{

}
Map_Windows::Map_Windows(String title, int width, int height, String backroundPath): rectSourceSprite(47, 0, 47, 75),window(title,width,height,backroundPath), viewItem_key_shop("Image/klucz.png",860,230), viewItem_figure("Image/postac.png",400,100), viewItem_key_arena("Image/klucz.png", 75, 820), viewItem_key_rest("Image/klucz.png", 840, 660)
{
	//window.create(sf::VideoMode(800, 600), "Window");

}

void Map_Windows::setPosition_figure(int x,int y)
{
	viewItem_figure.getImage().setPosition(x, y);

}


void Map_Windows::Start()
{
	
	viewItem_figure.getImage().setTextureRect(rectSourceSprite);
	while (window.getWindows().isOpen())
	{
		sleep(milliseconds(10));
		sf::Event event;
		while (window.getWindows().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.getWindows().close();
			}
		}
			if (event.type == Event::KeyPressed)
			{
				
				if (event.key.code == Keyboard::Up)
				{
					rectSourceSprite.top = 225;
					rectSourceSprite.height = 75;

					if (clock.getElapsedTime().asSeconds() > 0.2f) {
						if (rectSourceSprite.left == 94)
							rectSourceSprite.left = 0;
						else
							rectSourceSprite.left += 47;

						viewItem_figure.getImage().setTextureRect(rectSourceSprite);
						clock.restart();
					}

					if (viewItem_figure.getImage().getPosition().y > -5)
					{
						viewItem_figure.getImage().move(0, -1);
						cout << viewItem_figure.getImage().getPosition().y << " ";
					}
				}
				else if (event.key.code == Keyboard::Right)
				{
					rectSourceSprite.top = 150;
					rectSourceSprite.height = 75;
					if (clock.getElapsedTime().asSeconds() > 0.2f) {
						if (rectSourceSprite.left == 94)
							rectSourceSprite.left = 0;
						else
							rectSourceSprite.left += 47;

						viewItem_figure.getImage().setTextureRect(rectSourceSprite);
						clock.restart();
					}

					if (viewItem_figure.getImage().getPosition().x < 909)
					{
						viewItem_figure.getImage().move(1, 0);
						cout << viewItem_figure.getImage().getPosition().x << " ";
					}
				
				}
				else if (event.key.code == Keyboard::Left)
				{
					rectSourceSprite.top = 75;
					rectSourceSprite.height = 75;
					if (clock.getElapsedTime().asSeconds() > 0.2f) {
						if (rectSourceSprite.left == 94)
							rectSourceSprite.left = 0;
						else
							rectSourceSprite.left += 47;

						viewItem_figure.getImage().setTextureRect(rectSourceSprite);
						clock.restart();
					}

					if (viewItem_figure.getImage().getPosition().x > -2)
					{
					viewItem_figure.getImage().move(-1, 0);
					cout << viewItem_figure.getImage().getPosition().x << " ";
					}
				}
				else if (event.key.code == Keyboard::Down)
				{
					rectSourceSprite.top = 0;
					rectSourceSprite.height = 75;
					if (clock.getElapsedTime().asSeconds() > 0.2f) {
						if (rectSourceSprite.left == 94)
							rectSourceSprite.left = 0;
						else
							rectSourceSprite.left += 47;

						viewItem_figure.getImage().setTextureRect(rectSourceSprite);
						clock.restart();
					}
					
					if (viewItem_figure.getImage().getPosition().y < 855) 
					{
						viewItem_figure.getImage().move(0, 1);
						cout << viewItem_figure.getImage().getPosition().y << " ";	
					}
				}
				
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				sleep(milliseconds(700));

				window.getWindows().close();
				Menu menu("Game", 800, 600, "Image/mapMenu.png");
				menu.Start();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				

				if (viewItem_figure.getImage().getGlobalBounds().intersects(viewItem_key_shop.getImage().getGlobalBounds()))
				{
					window.getWindows().close();
					Shop_Windows aren_window;
					aren_window.Start();
				}
				else if (viewItem_figure.getImage().getGlobalBounds().intersects(viewItem_key_arena.getImage().getGlobalBounds()))
				{
					window.getWindows().close();
					Arena_Window aren_window;
					aren_window.Start();
				}
				else if (viewItem_figure.getImage().getGlobalBounds().intersects(viewItem_key_rest.getImage().getGlobalBounds()))
				{
					window.getWindows().close();
					Restaurant_Window aren_window;
					aren_window.Start();
				}
			}
		
		        window.getWindows().clear();
				window.getWindows().draw(window.backroundImage);
				window.getWindows().draw(viewItem_key_shop.getImage());
				window.getWindows().draw(viewItem_key_rest.getImage());
				window.getWindows().draw(viewItem_key_arena.getImage());
				window.getWindows().draw(viewItem_figure.getImage());
				window.getWindows().display();
	}
}