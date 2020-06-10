#include "Shop_Windows.h"


Shop_Windows::Shop_Windows():window("Shop", 950, 950, "Image/mapUi_shop.png")
{

}
Shop_Windows::~Shop_Windows()
{

}

void Shop_Windows::Start()
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
			map_windows.setPosition_figure(870, 220);
			map_windows.Start();
		}

	}
}