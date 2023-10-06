/**
 * @file CheapHotelShower.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CHEAPHOTELSHOWER_H
#define CHEAPHOTELSHOWER_H

#include <iostream>
#include <string>
#include <vector>

class CheapHotelShower {
public:
  float GetTemperature() const;
  float GetPower() const;
  float GetWater() const;
  float GetHumidity() const;
  float GetAirQuality() const;
  float GetWaterQuality() const;
  float GetNoise() const;
  float GetLight() const;
  float GetCO2() const;
  void SetTemperature(float temperature);
  void SetPower(float power);
  void SetWater(float water);
  void SetHumidity(float humidity);
  void SetAirQuality(float airQuality);
  void SetWaterQuality(float waterQuality);
  void SetNoise(float noise);
  void SetLight(float light);
  void SetCO2(float co2);

private:
  float temperature;
  float power;
  float water;
  float humidity;
  float airQuality;
  float waterQuality;
  float noise;
  float light;
  float co2;
};

#endif // CHEAPHOTELSHOWER_H
