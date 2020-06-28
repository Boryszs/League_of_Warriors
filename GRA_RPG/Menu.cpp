#include "Menu.h"
#include "Map_Windows.h"
#include <SFML/Graphics.hpp>
#include "ThrowLoad.cpp"
#include "DBcontroler.h"
#include "AddHeroe_Window.h"

Menu::~Menu()
{
	for (int i = 0; i < size + 1; i++)
		delete[] Text_Data[i];
	delete[] rectangle_choose;
}

Menu::Menu()
{
	//window.(sf::VideoMode(800, 600), "Window");
	//this->shape.setRadius(100);
}

Menu::Menu(String title,int width,int height,String backroundPath,int idUse):buttonStart(),buttonExit(),window(title,width,height,backroundPath),dbcontroler()
{
	//window.create(sf::VideoMode(width, height), title);
	//this->shape.setRadius(100);
	idUser = idUse;
	arial.loadFromFile("Fonts/Arial.ttf");

	this->width = width;
	this->height = height;
	background.loadFromFile(backroundPath);
	backroundImage.setTexture(background);
	buttonStart.setButton("Rozpocznij", 200, 50, Color::Black, 300, 250,340,260);
	buttonExit.setButton("Zakoncz", 200, 50, Color::Black, 300, 350,350, 360);
	//champion = champ;
	add_b.setSize(sf::Vector2f(100, 25));
	add_b.setPosition(225, 208);
	//add_b.setFillColor(Color::Cyan);

	delete_b.setSize(sf::Vector2f(117, 25));
	delete_b.setPosition(483, 208);
	//delete_b.setFillColor(Color::Cyan);


	if (!backgroundTab.loadFromFile("Image/tabela.png"))
	{
		throw MyException("Error module load");
	}
	backroundTable.setTexture(backgroundTab);
	backroundTable.setPosition(100,50);

	res = dbcontroler.getChampions(idUser);

	size = res->row_count;
	rectangle_choose = new RectangleShape[size];
	for (int i = 0; i < size; i++)
	{
		rectangle_choose[i].setPosition(100,80+(i*40));
		rectangle_choose[i].setSize(sf::Vector2f(600, 40));
	}

	Text_Data = new Text*[(size+1)];
	for (int i = 0; i <size+1; i++)
	{
		Text_Data[i] = new Text[4];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Text_Data[i][j].setFillColor(sf::Color::Black);
			Text_Data[i][j].setFont(arial);
			Text_Data[i][j].setCharacterSize(16);
			if(j==0)
			{
					Text_Data[i][j].setPosition(120, 90+(i*40));
			}
			else if(j==1)
			{
			    	Text_Data[i][j].setPosition(390, 90 + (i * 40));
			}
			else if (j == 2)
			{
				Text_Data[i][j].setPosition(580, 90 + (i * 40));
			}
		}
	}


	int count = 0;
		while (row = mysql_fetch_row(res))
		{
			Text_Data[count][0].setString(row[4]);
			Text_Data[count][1].setString(row[5]);
			if (atoi(row[3]) == 1)
			{
				Text_Data[count][2].setString("Warrior");
			}
			if (atoi(row[3]) == 2)
			{
				Text_Data[count][2].setString("Archer");
			}
			if (atoi(row[3]) == 3)
			{
				Text_Data[count][2].setString("Wizzard");
			}
			Text_Data[count][3].setString(row[1]);
			//cout << row[3] << " " << row[4] << " " << row[5] << endl;
			count++;
		}
		choose = -1;
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
					if (choose != -1)
					{
						window.getWindows().close();
						std::string tt = Text_Data[choose][3].getString();
						champion = dbcontroler.getChampion(std::atoi(tt.c_str()));
						Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png", champion,idUser);
						map_windows.Start();
					}
				}

				if (buttonExit.getButton().getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					window.getWindows().close();
				}

				if (add_b.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (size != 3)
					{
						window.getWindows().close();
						AddHeroe_Window Add_windows(idUser);
						Add_windows.Start();

					}
				}

				if (delete_b.getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (choose != -1)
					{
						std::string id_H = Text_Data[choose][3].getString();
						//cout << id_H;
						dbcontroler.deleteHeroes(idUser,atoi(id_H.c_str()));
						window.getWindows().close();
						Menu menu("Game", 800, 600, "Image/background.png", idUser);
						menu.Start();
					}
				}


				for (int i = 0; i < size; i++)
				{
					if (choose != -1)
					{
						rectangle_choose[choose].setFillColor(Color::White);
					}

					if (rectangle_choose[i].getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
					{
						rectangle_choose[i].setFillColor(Color::Blue);
						choose = i;	
						break;
					}
					else
					{
					rectangle_choose[i].setFillColor(Color::White);
					choose = -1;
					}
				}
				//cout << choose;
			}
		}

		window.getWindows().clear();
		window.getWindows().draw(add_b);
		window.getWindows().draw(delete_b);
		window.getWindows().draw(backroundImage);
		
		window.getWindows().draw(buttonStart.getButton());
		window.getWindows().draw(buttonStart.getText());
		window.getWindows().draw(buttonExit.getButton());
	
		window.getWindows().draw(buttonExit.getText());

		for (int i = 0; i < size; i++)
		{
			window.getWindows().draw(rectangle_choose[i]);
		}
		
		window.getWindows().draw(backroundTable);

		for (int i = 0; i <size; i++)
		{
			for (int j = 0; j <4; j++)
			{
					window.getWindows().draw(Text_Data[i][j]);
			}
		}

		window.getWindows().display();
	}

}
