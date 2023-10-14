/**
 * @file IdealHotelShower.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef IDEALHOTELSHOWER_H
#define IDEALHOTELSHOWER_H

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

class IdealHotelShower {
private:
  float _price;
  std::string _name;
  std::string _location;
  std::string _description;
  std::string _image;
  std::string _category;
  float _power;

public:
  float getPrice() const;
  void setPrice(float price);
  std::string getName() const;
  void setName(std::string name);
  std::string getLocation() const;
  void setLocation(std::string location);
  std::string getDescription() const;
  void setDescription(std::string description);
  std::string getImage() const;
  void setImage(std::string image);
  std::string getCategory() const;
  void setCategory(std::string category);
  float getPower() const;
  void setPower(float power);
};

#endif // IDEALHOTELSHOWER_H