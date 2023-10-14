/**
 * @file IdealHotelShower.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "IdealHotelShower.h"
#include <iostream>

// Implementation for GetTemperature

float IdealHotelShower::getPrice() const { return _price; }

std::string IdealHotelShower::getName() const { return _name; }

float IdealHotelShower::getPower() const { return _power; }

std::string IdealHotelShower::getLocation() const { return _location; }

std::string IdealHotelShower::getImage() const { return _image; }

std::string IdealHotelShower::getCategory() const { return _category; }

void IdealHotelShower::setPrice(float price) { _price = price; }

void IdealHotelShower::setName(std::string name) { _name = name; }

void IdealHotelShower::setPower(float power) { _power = power; }

void IdealHotelShower::setLocation(std::string location) {
  _location = location;
}

void IdealHotelShower::setImage(std::string image) { _image = image; }



