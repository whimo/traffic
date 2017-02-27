#include <SFML/Graphics.hpp>

#include "Road.cpp"
#include "Vehicle.cpp"

#include <iostream>
#include <cstdint>

const size_t WindowHeight = 512;

const size_t LaneWidth = 20, DefaultLanesNum = 3;
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
	sf::RenderWindow window (sf::VideoMode (LaneWidth * DefaultLanesNum, WindowHeight), "Traffic simulation");
	window.setFramerateLimit (60);
	window.setKeyRepeatEnabled (false);

	sf::Clock clock;
	
	Road road (DefaultLanesNum);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent (event))
		{
			if (event.type  == sf::Event::Closed)
				window.close ();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::S)
				{
					road.add_lane ();
					window.setSize (sf::Vector2u (LaneWidth * road.get_lanes_num (), WindowHeight));

				}

				if (event.key.code == sf::Keyboard::A)
				{
					int8_t lanes_num = road.get_lanes_num ();

					if (lanes_num > 1)
					{
						road.remove_lane ();
						window.setSize (sf::Vector2u (LaneWidth * (lanes_num - 1), WindowHeight));
					}
				}
			}
		}

		window.clear ();

		sf::Time frame_time = clock.restart ();
		int32_t time = frame_time.asMilliseconds ();

		road.render (&window, LaneWidth, time, CarWidth, CarLength, WindowHeight);

		/*Vehicle new_vehicle = Vehicle (rand () % road.get_lanes_num (),
							   -double (CarLength), 10);
		road.add_vehicle (new_vehicle);*/



		window.display ();
	}
}
