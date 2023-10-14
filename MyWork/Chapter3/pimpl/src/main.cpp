/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "autotimer.h"
#include "impl.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

int main(int argc, char **argv) {
  std::unique_ptr<impl> pimpl(
      new impl("Timer", "A simple timer", std::chrono::milliseconds(1000)));
  pimpl->start();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  pimpl->stop();
  std::cout << "Done" << std::endl;
  return 0;
}