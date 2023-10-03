/**
 * @file hotelShower.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
using namespace std;

#include "hotelShower.h"

HotelShower::HotelShower() { std::string mName = "Hotel Shower"; }

HotelShower::~HotelShower() { std::cout << "HotelShower destructor called" << std::endl; }

void HotelShower::print() { std::cout << "HotelShower::print()" << std::endl; }




