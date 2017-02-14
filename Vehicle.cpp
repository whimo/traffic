/***********************************************************
 * Vehicle.cpp                                             *
 * The main vehicle class                                  *
 * IMPLEMENTATION                                          *
 *                                                         *
 * Author: Artemy Belousov aka whimo                       *
 ***********************************************************/

#include "Vehicle.hpp"

Vehicle::Vehicle (double new_speed, double new_coord):
	speed (new_speed),
	coord (new_coord)
	{}

void Vehicle::move (double time)
{
	coord += speed * time;
}

double Vehicle::get_coord ()
{
	return coord;
}
