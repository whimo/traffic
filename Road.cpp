/***********************************************************
 * Road.cpp                                                *
 * The road class                                          *
 * IMPLEMENTATION                                          *
 *                                                         *
 * Author: Artemy Belousov aka whimo                       *
 ***********************************************************/

#include <iostream>
#include <vector>
#include <cstdint>

#include "Road.hpp"


Road::Road (uint8_t new_lanes_num):
	lanes_num (new_lanes_num)
	{}


void Road::add_vehicle (uint8_t lane, double coord, double speed)
{
	vehicles.push_back (Vehicle (lane, coord, speed));
}

void Road::add_vehicle (Vehicle vehicle)
{
	vehicles.push_back (vehicle);
}

void Road::change_lanes (uint8_t new_lanes_num)
{
	lanes_num = new_lanes_num;
}

void Road::add_lane (uint8_t num)
{
	lanes_num += num;
}

void Road::remove_lane (uint8_t num)
{
	lanes_num -= num;
}

int8_t Road::get_lanes_num ()
{
	return lanes_num;
}

void Road::render (sf::RenderWindow* window, 
				   size_t lane_width, 
				   int32_t time, 
				   size_t car_width,
				   size_t car_length,
				   int window_height)
{
	if (window_height == -1)
		window_height = window -> getSize ().y;

	for (int i = 0; i < vehicles.size (); i++)
	{
		sf::RectangleShape vehicle_shape (sf::Vector2f (car_width, car_length));
		vehicle_shape.setPosition ((lanes_num - 1) * lane_width + (lane_width - car_width)/2, window_height - vehicles [i].get_coord ());

		window -> draw (vehicle_shape);
		vehicles [i].move (time/100);
	}
}
