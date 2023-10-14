/**
 * @file main.c
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

int main() {
  // Create an instance of IdealHotelShower
  IdealHotelShower myShower;

  // Setting values
  myShower.setPrice(200.0);
  myShower.setName("LuxuryShower");
  myShower.setPower(1200.0);
  myShower.setLocation("Suite 101");
  myShower.setImage("luxuryshower.jpg");

  // Displaying values
  std::cout << "Shower Information: " << std::endl;
  std::cout << "Price: " << myShower.getPrice() << std::endl;
  std::cout << "Name: " << myShower.getName() << std::endl;
  std::cout << "Power: " << myShower.getPower() << "W" << std::endl;
  std::cout << "Location: " << myShower.getLocation() << std::endl;
  std::cout << "Image: " << myShower.getImage() << std::endl;

  return 0;
}
