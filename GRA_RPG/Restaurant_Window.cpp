#include "Restaurant_Window.h"
#include "Map_Windows.h"
#include "ThrowLoad.cpp"
#include "DBcontroler.h"
#include "RestaurantFight_Window.h"

Restaurant_Window::Restaurant_Window(Champion* champ,int idUse) :window("Restaurant", 950, 950, "Image/mapUi_res.png")
Restaurant_Window::Restaurant_Window(Champion* champ) :window("Restaurant", 950, 950, "Image/mapUi_res.png"), dbcontroler()
{
	champion = champ;
	arial.loadFromFile("Fonts/Arial.ttf");

	if (!backgroundTab.loadFromFile("Image/tabela.png"))
	{
		throw MyException("Error module load");
	}
	backroundTable.setTexture(backgroundTab);
	backroundTable.setPosition(200, 190);

	res = dbcontroler.randomChampion(champion->getId());

	if (res != nullptr)
	{
		buttonStart.setButton("Fight!", 200, 50, Color::Black, 400, 350, 465, 360);
		size = res->row_count;
		rectangle_choose = new RectangleShape[size];
		for (int i = 0; i < size; i++)
		{
			rectangle_choose[i].setPosition(200, 220 + (i * 40));
			rectangle_choose[i].setSize(sf::Vector2f(600, 40));
		}

		Text_Data = new Text * [(size + 1)];
		for (int i = 0; i < size + 1; i++)
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
				if (j == 0)
				{
					Text_Data[i][j].setPosition(220, 230 + (i * 40));
				}
				else if (j == 1)
				{
					Text_Data[i][j].setPosition(490, 230 + (i * 40));
				}
				else if (j == 2)
				{
					Text_Data[i][j].setPosition(680, 230 + (i * 40));
				}
			}
		}
	idUser = idUse;
}


		int count = 0;
		while (row = mysql_fetch_row(res))
		{
			Text_Data[count][0].setString(row[2]);
			Text_Data[count][1].setString(row[3]);
			if (atoi(row[1]) == 1)
			{
				Text_Data[count][2].setString("Warrior");
			}
			if (atoi(row[1]) == 2)
			{
				Text_Data[count][2].setString("Archer");
			}
			if (atoi(row[1]) == 3)
			{
				Text_Data[count][2].setString("Wizzard");
			}
			Text_Data[count][3].setString(row[0]);
			count++;
		}
	}
	choose = -1;
}

Restaurant_Window::~Restaurant_Window()
{

}

void Restaurant_Window::Start()
{
	while (window.getWindows().isOpen())
	{
		sf::Event event;
		while (window.getWindows().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				sleep(milliseconds(700));
				window.getWindows().close();
				Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png", champion,idUser);
				map_windows.setPosition_figure(840, 660);
				map_windows.Start();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (buttonStart.getButton().getGlobalBounds().contains(this->window.getWindows().mapPixelToCoords(sf::Mouse::getPosition(this->window.getWindows()))))
				{
					if (choose != -1)
					{
						window.getWindows().close();
						std::string tt = Text_Data[choose][3].getString();
						cout << "\n\n" << std::atoi(tt.c_str()) << "\n\n" << endl;
						Champion* oponnent = dbcontroler.getChampion(std::atoi(tt.c_str()));
						cout << *oponnent << endl;

						RestaurantFight_Window arenFight_window(champion, oponnent);
						arenFight_window.Start();
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
			}

		}
		
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			sleep(milliseconds(700));
			window.getWindows().close();
			Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png",champion,idUser);
			map_windows.setPosition_figure(840, 660);
			map_windows.Start();
		}
	

		window.getWindows().clear();
		window.getWindows().draw(window.backroundImage);
		window.getWindows().draw(buttonStart.getButton());
		window.getWindows().draw(buttonStart.getText());

		for (int i = 0; i < size; i++)
		{
			window.getWindows().draw(rectangle_choose[i]);
		}

		window.getWindows().draw(backroundTable);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				window.getWindows().draw(Text_Data[i][j]);
			}
		}

		window.getWindows().display();
	}
}