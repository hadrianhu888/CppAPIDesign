/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "MobilePhone.h"
#include <iostream>
#include <string>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MobilePhone MobilePhone;

int main(int argc, char *argv[]) {
  MobilePhone myPhone("Galaxy S25", "Samsung", "Android");

  // Display details of the phone
  std::cout << "Model: " << myPhone.getModel() << std::endl;
  std::cout << "Manufacturer: " << myPhone.getManufacturer() << std::endl;
  std::cout << "Operating System: " << myPhone.getOperatingSystem()
            << std::endl;

  // Make a call
  myPhone.makeCall("123-456-7890");

  // Send a message
  myPhone.sendMessage("123-456-7890", "Hello from my new phone!");

  // Checking features of the phone
  std::cout << "Has GPS? " << (myPhone.hasGPS() ? "Yes" : "No") << std::endl;
  std::cout << "Has Bluetooth? " << (myPhone.hasBluetooth() ? "Yes" : "No")
            << std::endl;
  // ... you can continue this for other features

  // Retrieve GPS Location
  double latitude, longitude;
  if (myPhone.GetGPSLocation(latitude, longitude)) {
    std::cout << "Current GPS Location: Latitude: " << latitude
              << ", Longitude: " << longitude << std::endl;
  }

  return 0;
}

#ifdef __cplusplus
}
#endif // MAIN_C
