#include <SFML/Graphics.hpp>

#include "Road.hpp"
#include "Vehicle.cpp"

#include <iostream>
#include <cstdint>

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
	window.setFramerateLimit (60);

	sf::Clock clock;
	
	Lane lane;
	lane.vehicles.push_back (Vehicle (10, 0));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent (event))
		{
			if (event.type  == sf::Event::Closed)
				window.close ();
		}

		window.clear ();

		sf::Time frame_time = clock.restart ();
		int32_t time = frame_time.asMilliseconds ();

		for (int i = 0; i < lane.vehicles.size (); i++)
		{
			sf::RectangleShape car (sf::Vector2f (CarWidth, CarLength));

			double position = lane.vehicles [i].get_coord ();

			if (position > WindowHeight)
			{
				lane.vehicles.erase (lane.vehicles.begin () + i);
				lane.vehicles.push_back (Vehicle (10, -int (CarLength)));
			}

			car.setPosition ((WindowWidth - CarWidth)/2, position);


			window.draw (car);

			lane.vehicles [i].move (time/100.0);
		}
		window.display ();
	}
}

