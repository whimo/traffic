#include <SFML/Graphics.hpp>

#include "Road.hpp"
#include "Vehicle.hpp"

const size_t WindowWidth = 32, WindowHeight = 512;

const size_t CarWidth = 16, CarLength = 64;


void mainloop ();

void render_vehicle (Vehicle vehicle);


int main ()
{
	mainloop ();

	return 0;
}

void mainloop ()
{
	sf::RenderWindow window (sf::VideoMode (WindowWidth, WindowHeight), "Traffic simulation");
	
	Lane lane;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent (event))
		{
			if (event.type  == sf::event::Closed)
				window.close ();
		}

		window.clear ();

		for (int i = 0; i < lane.vehicles.size (); i++)
		{
			sf::RectangleShape car (sf::Vector2f (CarWidth, CarLength));
			car.setPosition ((WindowWidth - CarWidth)/2, lane.vechicles [i].coord);

			window.draw (car);
		}
	}
}

