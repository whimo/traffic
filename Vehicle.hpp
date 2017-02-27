/***********************************************************
 * Vehicle.hpp                                             *
 * The main vehicle class                                  *
 *                                                         *
 * Author: Artemy Belousov aka whimo                       *
 ***********************************************************/

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <cstdint>

class Vehicle
{
private:
	int8_t lane_n;

	double speed;
	double coord;

public:
	Vehicle (uint8_t new_lane, double new_coord, double new_speed);

	void move (double time);

	double get_coord ();
	int8_t get_lane ();
};

#endif //VEHICLE_HPP
