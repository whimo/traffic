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

Vehicle get_vehicle_in_front (Vehicle vehicle)
{
	Vehicle vehicle_in_front = NULL;

	for (int i = 0; i < vehicles.size (); i++)
	{
		coord = vehicles [i].get_coord ();
		if (vehicles [i].get_lane () == vehicle.get_lane () && coord > vehicle.get_coord ())
			if (vehicle_in_front == NULL || coord < vehicle_in_front.get_coord ())
				vehicle_in_front = vehicles [i];
	}

	return vehicle_in_front;
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
				   size_t car_width,
				   size_t car_length,
				   int window_height)
{
	if (window_height == -1)
		window_height = window -> getSize ().y;

	for (int i = 0; i < vehicles.size (); i++)
	{
		sf::RectangleShape vehicle_shape (sf::Vector2f (car_width, car_length));
		vehicle_shape.setPosition ((vehicles [i].get_lane ()) * lane_width + (lane_width - car_width)/2, window_height - vehicles [i].get_coord ());

		window -> draw (vehicle_shape);
	}
}

void Road::move (int32_t time, int32_t max_coord, double critical_distance)
{
	for (int i = 0; i < vehicles.size (); i++)
	{
		vehicle_in_front = get_vehicle_in_front (vehicles [i]);
		if (vehicle_in_front != NULL)
			if (vehicle_in_front.get_coord () - vehicles [i].get_coord () <= critical_distance)
				vehicles [i].set_speed (vehicle_in_front.get_speed ())

		vehicles [i].move (double (time)/100);

		if (vehicles [i].get_coord () >= max_coord)
			vehicles.erase (vehicles.begin () + i);
	}
}