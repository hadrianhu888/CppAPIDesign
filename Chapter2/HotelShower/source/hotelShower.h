/**
 * @file hotelShower.h
 * @brief Header file for the HotelShower class
 * @version 0.1
 * @date 2023-10-02
 */

#ifndef _HOTEL_SHOWER_H
#define _HOTEL_SHOWER_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

class HotelShower {
private:
    std::vector<std::string> rooms;

public:
    HotelShower();
    ~HotelShower();
    void print();
};
#endif
