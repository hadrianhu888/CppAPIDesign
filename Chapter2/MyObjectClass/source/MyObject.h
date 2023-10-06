/**
 * @file MyObject.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

template <typename T> using MyObjectMap = std::map<std::string, T>;

typedef std::shared_ptr<class MyObject> MyObjectPtr;
class MyObject {
  std::string name;
  MyObjectMap<std::string> values;
  MyObjectMap<std::string> defaultValues;
  std::vector<std::string> keys;
  std::vector<std::string> defaultKeys;

private:      // private constructor
  MyObject(); // default constructor)

protected:
  MyObject(std::string name);

public:
  static MyObjectPtr createInstance();
  virtual ~MyObject();
  virtual void reset();
  virtual void print();
  virtual void set(std::string key, std::string value);
  virtual std::string get(std::string key);
};

#endif // MYOBJECT_H
