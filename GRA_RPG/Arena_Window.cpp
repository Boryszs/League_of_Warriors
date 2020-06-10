#include "Arena_Window.h"
#include "Map_Windows.h"

Arena_Window::Arena_Window():window("Arena",950, 950, "Image/mapUi_arena.png"),hydra("Image/m2.png",560,560)
{

}

Arena_Window::~Arena_Window() 
{

}

void Arena_Window::Start()
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
			window.getWindows().draw(hydra.getImage());
			window.getWindows().display();
		}
	  if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
		     sleep(milliseconds(700));
			 window.getWindows().close();
			 Map_Windows map_windows("Gra", 950, 950, "Image/mapo.png");
			 map_windows.setPosition_figure(80, 805);
			 map_windows.Start();
		}

	}
}