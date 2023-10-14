/**
 * @file MobilePhone.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright Copyright (c) 2023
 *
 */
/**
public:
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
*/
#include "MobilePhone.h"
#include <iostream>
#include <string>

MobilePhone::MobilePhone(const std::string &model,
                         const std::string &manufacturer,
                         const std::string &operatingSystem) {
  this->model = model;
  this->manufacturer = manufacturer;
  this->operatingSystem = operatingSystem;
}

MobilePhone::~MobilePhone() {}

void MobilePhone::makeCall(const std::string &phoneNumber) {
  std::cout << "Calling " << phoneNumber << std::endl;
}

void MobilePhone::sendMessage(const std::string &phoneNumber,
                              const std::string &message) {
  std::cout << "Sending message to " << phoneNumber << std::endl;
  std::cout << message << std::endl;
}

std::string MobilePhone::getModel() const { return model; }

std::string MobilePhone::getManufacturer() const { return manufacturer; }

std::string MobilePhone::getOperatingSystem() const { return operatingSystem; }

bool MobilePhone::StartCall(const std::string &phoneNumber) {
  std::cout << "Calling " << phoneNumber << std::endl;
  return true;
}

bool MobilePhone::EndCall(const std::string &phoneNumber) {
  std::cout << "Ending call with " << phoneNumber << std::endl;
  return true;
}

bool MobilePhone::SendMessage(const std::string &phoneNumber,
                              const std::string &message) {
  std::cout << "Sending message to " << phoneNumber << std::endl;
  std::cout << message << std::endl;
  return true;
}

bool MobilePhone::hasGPS() const { return true; }

bool MobilePhone::hasBluetooth() const { return true; }

bool MobilePhone::hasNFC() const { return true; }

bool MobilePhone::hasTouchScreen() const { return true; }

bool MobilePhone::hasWifi() const { return true; }

bool MobilePhone::hasSDCardSlot() const { return true; }

bool MobilePhone::hasPhysicalKeyboard() const { return true; }

bool MobilePhone::hasFrontCamera() const { return true; }

bool MobilePhone::hasBackCamera() const { return true; }

bool MobilePhone::hasFlash() const { return true; }

bool MobilePhone::hasUSBPort() const { return true; }

bool MobilePhone::hasHeadphoneJack() const { return true; }

bool MobilePhone::hasFingerprintScanner() const { return true; }

bool MobilePhone::hasFaceScanner() const { return true; }

bool MobilePhone::hasIrisScanner() const { return true; }

bool MobilePhone::hasHeartRateSensor() const { return true; }

bool MobilePhone::GetGPSLocation(double &latitude, double &longitude) const {
  latitude = 0.0;
  longitude = 0.0;
  return true;
}

// Path: Chapter2/SmartPhone/SmartPhone.cpp
/**
 * @file SmartPhone.cpp
 * @brief
 * @version 0.1
 * @date 2023-10-05
 *
 *
 */
