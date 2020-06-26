#include "Restaurant_Window.h"
#include "Map_Windows.h"

Restaurant_Window::Restaurant_Window(Champion* champ) :window("Restaurant", 950, 950, "Image/mapUi_res.png")
{
	champion = champ;
}

Restaurant_Window::~Restaurant_Window()
{

}

void Restaurant_Window::Start()
{
	while (window.getWindows().isOpen())
	{
		sleep(milliseconds(3));
		sf::Event event;
		while (window.getWindows().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				sleep(milliseconds(700));
				window.getWindows().close();
				Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png", champion);
				map_windows.setPosition_figure(840, 660);
				map_windows.Start();
			}

		}
		
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			sleep(milliseconds(700));
			window.getWindows().close();
			Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png",champion);
			map_windows.setPosition_figure(840, 660);
			map_windows.Start();
		}
	

		window.getWindows().clear();
		window.getWindows().draw(window.backroundImage);
		window.getWindows().display();
	}
}