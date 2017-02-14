/***********************************************************
 * Vehicle.hpp                                             *
 * The main vehicle class                                  *
 *                                                         *
 * Author: Artemy Belousov aka whimo                       *
 ***********************************************************/

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class Vehicle
{
private:
	double speed;
	double  coord;

public:
	Vehicle (double new_speed = 0, double new_coord = 0);

	void move (double time);

	double get_coord ();
};

#endif //VEHICLE_HPP
