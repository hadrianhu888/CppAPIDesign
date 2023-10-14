/**
 * @file MySlot.cpp
 * @brief Implementation of the MySlot class
 * @version 0.1
 * @date 2023-10-12
 */

#include <iostream>
#include <string>

#include "MySlot.h"

MySlot::MySlot() {
  // Constructor implementation
  /**
   * @brief initialize the slot object
   *
   */
  std::cout << "MySlot constructor" << std::endl;
}

MySlot::~MySlot() {
  // Destructor implementation
  std::cout << "MySlot destructor" << std::endl;
}

void MySlot::operator()() const {
  // Function call operator implementation
  std::cout << "MySlot function call operator" << std::endl;
}

void MySlot::onSignalReceived(const string &signal) {
  // onSignalReceived implementation with a string parameter
  std::cout << "MySlot onSignalReceived with a string parameter" << std::endl;
}

void MySlot::onSignalReceived(const function<void()> &callback) {
  // onSignalReceived implementation with a function callback parameter
  std::cout << "MySlot onSignalReceived with a function callback parameter"
            << std::endl;
}

// You can implement the member functions here or in a separate .cpp file.
