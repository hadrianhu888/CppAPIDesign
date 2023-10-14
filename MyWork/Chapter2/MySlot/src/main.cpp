/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <functional>
#include <iostream>
#include <string>

#include "main.h"

int main(int argc, char **argv) {
  // Create a slot object
  MySlot slot;
  slot.operator()();
  slot.onSignalReceived("Hello World");
  slot.onSignalReceived([]() { std::cout << "Hello World" << std::endl; });
  return 0;
}