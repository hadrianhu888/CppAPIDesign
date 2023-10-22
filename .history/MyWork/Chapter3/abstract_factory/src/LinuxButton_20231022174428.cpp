#include "LinuxButton.h"
#include <iostream>

void LinuxButton::click() { std::cout << "Linux Button clicked.\n"; }

void LinuxButton::paint() { std::cout << "Linux Button painted.\n"; }

void LinuxButton::setColor(const std::string &color) {
  std::cout << "Linux Button color changed to " << color << ".\n";
}

void LinuxButton::set