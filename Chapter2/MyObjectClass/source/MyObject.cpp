/**
 * @file MyObject.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "MyObject.h"

#include "MyObject.h"

// Define the static function to create an instance of MyObject
MyObjectPtr MyObject::createInstance() { return MyObjectPtr(new MyObject()); }

MyObject::MyObject() {
  // Constructor code, if any
  std::cout << "Constructor called" << std::endl;
}

MyObject::MyObject(std::string name) {
  // Constructor code, if any
  std::cout << "Constructor called" << std::endl;
  this->name = name;
}


// Define the destructor
MyObject::~MyObject() {
  // Destructor code, if any
	std::cout << "Destructor called" << std::endl;
}

void MyObject::reset() {
  // Call destructor
	this->~MyObject();
}

void MyObject::print() {
	std::cout << "MyObject::print()" << std::endl;
}

void MyObject::set(std::string key, std::string value) {
	std::cout << "MyObject::set(" << key << ", " << value << ")" << std::endl;
}

std::string MyObject::get(std::string key) {
        std::cout << "MyObject::get(" << key << ")" << std::endl;
        return "Hello World!";
}


