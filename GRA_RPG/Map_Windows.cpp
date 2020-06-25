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
Map_Windows::Map_Windows(String title, int width, int height, String backroundPath, Champion* champ): dbcontroler(),rectSourceSprite(47, 0, 47, 75),window(title,width,height,backroundPath), viewItem_key_shop("Image/klucz.png",860,230), viewItem_figure("Image/postac.png",400,100), viewItem_key_arena("Image/klucz.png", 75, 820), viewItem_key_rest("Image/klucz.png", 840, 660)
{
	//window.create(sf::VideoMode(800, 600), "Window");
	champion = champ;
	col_l_u_1.setSize(sf::Vector2f(280, 230));
	col_l_u_1.setPosition(0, 0);
	col_l_u_1.setFillColor(Color::Yellow);

	col_l_u_2.setSize(sf::Vector2f(375, 110));
	col_l_u_2.setPosition(0, 0);
	col_l_u_2.setFillColor(Color::Green);

	col_r_u_1.setSize(sf::Vector2f(440, 190));
	col_r_u_1.setPosition(510, 0);
	col_r_u_1.setFillColor(Color::Green);

	col_r_u_2.setSize(sf::Vector2f(215, 80));
	col_r_u_2.setPosition(570, 170);
	col_r_u_2.setFillColor(Color::Green);

	col_l_d_1.setSize(sf::Vector2f(280, 310));
	col_l_d_1.setPosition(0, 390);
	col_l_d_1.setFillColor(Color::Yellow);


	col_l_d_2.setSize(sf::Vector2f(117, 300));
	col_l_d_2.setPosition(260, 480);
	col_l_d_2.setFillColor(Color::Green);


	col_r_d_1.setSize(sf::Vector2f(420, 230));
	col_r_d_1.setPosition(635, 385);
	col_r_d_1.setFillColor(Color::Green);

	col_r_d_2.setSize(sf::Vector2f(310, 280));
	col_r_d_2.setPosition(510, 470);
	col_r_d_2.setFillColor(Color::Green);


	col_r_d_3.setSize(sf::Vector2f(70, 130));
	col_r_d_3.setPosition(900, 730);
	col_r_d_3.setFillColor(Color::Yellow);

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
//					cout << *champion << endl;
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
						if (!col_l_u_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_l_u_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_u_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_r_u_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_l_d_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_l_d_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_d_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_r_d_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_d_3.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()))
						{
							viewItem_figure.getImage().move(0, -1);
							cout << viewItem_figure.getImage().getPosition().y << " ";
							
						}
						else
						{
							viewItem_figure.getImage().move(0, 35);
						}
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
						if (!col_l_u_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_l_u_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_u_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_r_u_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_l_d_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_l_d_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_d_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_r_d_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_d_3.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()))
						{
							viewItem_figure.getImage().move(1, 0);
							cout << viewItem_figure.getImage().getPosition().y << " ";

						}
						else
						{
							viewItem_figure.getImage().move(-35, 0);
						}
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
						if (!col_l_u_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_l_u_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_u_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_r_u_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_l_d_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_l_d_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_d_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_r_d_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_d_3.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()))
						{
							viewItem_figure.getImage().move(-1, 0);
							cout << viewItem_figure.getImage().getPosition().y << " ";

						}
						else
						{
							viewItem_figure.getImage().move(35,0);
						}
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
						if (!col_l_u_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_l_u_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_u_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_r_u_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_l_d_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_l_d_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_d_1.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) && !col_r_d_2.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()) &&
							!col_r_d_3.getGlobalBounds().intersects(viewItem_figure.getImage().getGlobalBounds()))
						{
							viewItem_figure.getImage().move(0, 1);
							cout << viewItem_figure.getImage().getPosition().y << " ";

						}
						else
						{
							viewItem_figure.getImage().move(0,-35);
						}
					}
				}
				
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				dbcontroler.updateChampion(champion);
				sleep(milliseconds(700));
				
				window.getWindows().close();
				Menu menu("Game", 800, 600, "Image/background.png",champion);
				menu.Start();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				

				if (viewItem_figure.getImage().getGlobalBounds().intersects(viewItem_key_shop.getImage().getGlobalBounds()))
				{
					window.getWindows().close();
					Shop_Windows aren_window(champion);
					aren_window.Start();
				}
				else if (viewItem_figure.getImage().getGlobalBounds().intersects(viewItem_key_arena.getImage().getGlobalBounds()))
				{
					window.getWindows().close();
					Arena_Window aren_window(champion);
					aren_window.Start();
				}
				else if (viewItem_figure.getImage().getGlobalBounds().intersects(viewItem_key_rest.getImage().getGlobalBounds()))
				{
					window.getWindows().close();
					Restaurant_Window aren_window(champion);
					aren_window.Start();
				}
			}
		
		        window.getWindows().clear();
				window.getWindows().draw(col_l_u_1);
				window.getWindows().draw(col_l_u_2);
				window.getWindows().draw(col_r_u_1);
				window.getWindows().draw(col_r_u_2);
				window.getWindows().draw(col_l_d_1);
				window.getWindows().draw(col_l_d_2);
				window.getWindows().draw(col_r_d_1);
				window.getWindows().draw(col_r_d_2);
				window.getWindows().draw(col_r_d_3);
				window.getWindows().draw(window.backroundImage);
				window.getWindows().draw(viewItem_key_shop.getImage());
				window.getWindows().draw(viewItem_key_rest.getImage());
				window.getWindows().draw(viewItem_key_arena.getImage());

				window.getWindows().draw(viewItem_figure.getImage());
			
				window.getWindows().display();
	}
}