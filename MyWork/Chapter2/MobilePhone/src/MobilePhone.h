/**
 * @file MobilePhone.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MOBILE_PHONE_H
#define MOBILE_PHONE_H

#include <string>
#include <vector>
#include <iostream>

class MobilePhone {
public:
  std::string m_phoneNumber;
  std::string model;
  std::string manufacturer;
  std::string operatingSystem;
  MobilePhone(const std::string &model, const std::string &manufacturer,
              const std::string &operatingSystem);
  ~MobilePhone();

  void makeCall(const std::string &phoneNumber);
  void sendMessage(const std::string &phoneNumber, const std::string &message);

  std::string getModel() const;
  std::string getManufacturer() const;
  std::string getOperatingSystem() const;

  bool StartCall(const std::string &phoneNumber);
  bool EndCall(const std::string &phoneNumber);
  bool SendMessage(const std::string &phoneNumber, const std::string &message);
  bool hasGPS() const;
  bool hasBluetooth() const;
  bool hasNFC() const;
  bool hasTouchScreen() const;
  bool hasWifi() const;
  bool hasSDCardSlot() const;
  bool hasPhysicalKeyboard() const;
  bool hasFrontCamera() const;
  bool hasBackCamera() const;
  bool hasFlash() const;
  bool hasUSBPort() const;
  bool hasHeadphoneJack() const;
  bool hasFingerprintScanner() const;
  bool hasFaceScanner() const;
  bool hasIrisScanner() const;
  bool hasHeartRateSensor() const;
  bool GetGPSLocation(double &latitude, double &longitude) const;

private:
  std::string m_model;
  std::string m_manufacturer;
  std::string m_operatingSystem;
  bool m_hasGPS;
  bool m_hasBluetooth;
  bool m_hasNFC;
  bool m_hasTouchScreen;
  bool m_hasWifi;
  bool m_hasSDCardSlot;
  bool m_hasPhysicalKeyboard;
  bool m_hasFrontCamera;
  bool m_hasBackCamera;
  bool m_hasFlash;
  bool m_hasUSBPort;
  bool m_hasHeadphoneJack;
  bool m_hasFingerprintScanner;
  bool m_hasFaceScanner;
  bool m_hasIrisScanner;
  bool m_hasHeartRateSensor;
  double m_latitude;
  double m_longitude;
};

#endif // MOBILE_PHONE_H
