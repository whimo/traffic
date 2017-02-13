/***********************************************************
 * Vehicle.hpp                                             *
 * The road class                                          *
 *                                                         *
 * Author: Artemy Belousov aka whimo                       *
 ***********************************************************/

#include <iostream>
#include <vector>

#include "Vehicle.hpp"

class Lane
{
public:
	std::vector <Vehicle> vehicles;
};

class Road
{
private:
	uint8_t lanes_num;
	std::vector <Lane> lanes;

};
