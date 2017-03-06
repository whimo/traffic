/***********************************************************
 * Vehicle.cpp                                             *
 * The main vehicle class                                  *
 * IMPLEMENTATION                                          *
 *                                                         *
 * Author: Artemy Belousov aka whimo                       *
 ***********************************************************/

#include "Vehicle.hpp"

#include <iostream>
#include <cstdint>


Vehicle::Vehicle (uint8_t new_lane, double new_coord, double new_speed):
	lane_n (new_lane),
	coord  (new_coord),
	speed  (new_speed)
	{}

void Vehicle::move (double time)
{
	coord += speed * time;
}

void Vehicle::set_speed (double new_speed)
{
	speed = new_speed;
}

double Vehicle::get_coord ()
{
	return coord;
}

int8_t Vehicle::get_lane ()
{
	return lane_n;
}