/***********************************************************
 * Road.hpp                                                *
 * The road class                                          *
 *                                                         *
 * Author: Artemy Belousov aka whimo                       *
 ***********************************************************/

#ifndef ROAD_HPP
#define ROAD_HPP

#include <iostream>
#include <vector>

#include <cstdint>

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

#endif //ROAD_HPP
