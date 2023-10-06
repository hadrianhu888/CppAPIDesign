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

#include "CheapHotelShower.h"
#include <iostream>

int main() {
  CheapHotelShower myShower;

  // Test SetTemperature and GetTemperature
  myShower.SetTemperature(37.5);
  std::cout << "Temperature: " << myShower.GetTemperature() << " degrees"
            << std::endl;

  // Test SetPower and GetPower
  myShower.SetPower(75.0);
  std::cout << "Power: " << myShower.GetPower() << "%" << std::endl;

  // Test SetWater and GetWater
  myShower.SetWater(10.0);
  std::cout << "Water: " << myShower.GetWater() << " liters" << std::endl;

  // Test SetHumidity and GetHumidity
  myShower.SetHumidity(40.0);
  std::cout << "Humidity: " << myShower.GetHumidity() << "%" << std::endl;

  // Test SetAirQuality and GetAirQuality
  myShower.SetAirQuality(95.0);
  std::cout << "Air Quality: " << myShower.GetAirQuality() << "%" << std::endl;

  // Test SetWaterQuality and GetWaterQuality
  myShower.SetWaterQuality(90.0);
  std::cout << "Water Quality: " << myShower.GetWaterQuality() << "%"
            << std::endl;

  // Test SetNoise and GetNoise
  myShower.SetNoise(35.0);
  std::cout << "Noise: " << myShower.GetNoise() << " dB" << std::endl;

  // Test SetLight and GetLight
  myShower.SetLight(300.0);
  std::cout << "Light: " << myShower.GetLight() << " lumens" << std::endl;

  // Test SetCO2 and GetCO2
  myShower.SetCO2(500.0);
  std::cout << "CO2: " << myShower.GetCO2() << " ppm" << std::endl;

  return 0;
}
