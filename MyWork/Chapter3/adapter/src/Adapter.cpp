/**
 * @file Adapter.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Adapter.h"

Adapter::Adapter() {}

void Adapter::print() { std::cout << "Adapter::print()" << std::endl; }

Adapter::Adapter(const Adapter &) {}

Adapter &Adapter::operator=(const Adapter &) { return *this; }

Adapter &Adapter::operator=(Adapter &&) { return *this; }

Adapter Adapter::getInstance() {
  static Adapter instance;
  return instance;
}

Adapter::~Adapter() {
  static Adapter *instance = nullptr;
  instance = nullptr;
  delete instance;
}

Adapter Adapter::getInstance(std::string str) {
  static Adapter instance;
  return instance;
}

Adapter Adapter::getInstance(int num) {
  static Adapter instance;
  return instance;
}