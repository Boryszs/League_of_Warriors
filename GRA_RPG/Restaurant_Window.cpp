#include "Restaurant_Window.h"
#include "Map_Windows.h"

Restaurant_Window::Restaurant_Window() :window("Restaurant", 950, 950, "Image/mapUi_res.png")
{

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
				window.getWindows().close();


			window.getWindows().clear();
			window.getWindows().draw(window.backroundImage);
			window.getWindows().display();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			sleep(milliseconds(700));
			window.getWindows().close();
			Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png");
			map_windows.setPosition_figure(840, 660);
			map_windows.Start();
		}

	}
}