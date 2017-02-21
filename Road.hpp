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
#include <SFML/Graphics.hpp>


class Road
{
private:
	uint8_t lanes_num;
	std::vector <Vehicle> vehicles;

public:
	Road (uint8_t new_lanes_num);

	void add_vehicle (uint8_t lane, double coord, double speed);
	void add_vehicle (Vehicle vehicle);

	void change_lanes (uint8_t new_lanes_num);

	void add_lane    (uint8_t num = 1);
	void remove_lane (uint8_t num = 1);

	int8_t get_lanes_num ();

	void render (sf::RenderWindow* window, 
				 size_t lane_width, 
				 int32_t time, 
				 size_t CarWidth = 16,
				 size_t CarLength = 64,
				 int window_height = -1);
};

#endif //ROAD_HPP
