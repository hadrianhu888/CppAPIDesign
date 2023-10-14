/**
 * @file MyCustomObject.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MY_CUSTOM_OBJECT_H
#define MY_CUSTOM_OBJECT_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace my_custom_object {
class MyCustomObject {
public:
  MyCustomObject();
  ~MyCustomObject();
  void print();
  void setName(std::string name);
  void setAge(int age);
  void setHeight(double height);
  void setWeight(double weight);
  void setGender(std::string gender);
  void setHairColor(std::string hair_color);
  void setMap(std::map<std::string, std::string> map);
  void
  setMapIterator(std::map<std::string, std::string>::iterator map_iterator);
  void setVector(std::vector<std::string> vector);
  void setVectorIterator(std::vector<std::string>::iterator vector_iterator);
  void setSharedPtr(std::shared_ptr<std::string> shared_ptr);
  void setSharedPtrIterator(
      std::iterator<std::string, std::string>::pointer shared_ptr_iterator);
  std::map<std::string, std::string> getMap();

private:
  std::string m_name;
  int m_age;
  double m_height;
  double m_weight;
  std::string m_gender;
  std::string m_hair_color;
  std::map<std::string, std::string> m_map;
  std::map<std::string, std::string>::iterator m_map_iterator;
};
} // namespace my_custom_object

#endif // MY_CUSTOM_OBJECT_H
