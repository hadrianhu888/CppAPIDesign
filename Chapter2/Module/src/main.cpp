/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "main.h"
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

// Define a simple callback function
void sampleCallback() {
  std::cout << "Sample callback function executed!" << std::endl;
}

int main(int argc, char **argv) {
  // Create an instance of the ModuleA class, providing the sample callback
  moduleA::ModuleA moduleInstance(sampleCallback);

  // Start the module
  moduleInstance.start();

  // Send and receive a message
  moduleInstance.send("Hello from main!");
  moduleInstance.receive("Hello to main!");

  // Run the module
  moduleInstance.run();

  // Notify waiting threads (if any)
  moduleInstance.notify();

  // Stop the module
  moduleInstance.stop();

  return 0;
}
