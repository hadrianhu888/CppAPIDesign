#include "LinuxButton.h"
#include <iostream>

void LinuxButton::click() { std::cout << "Linux Button clicked.\n"; }

void LinuxButton::paint() { std::cout << "Linux Button painted.\n"; }

void LinuxButton::setColor(const std::string &color) {
  std::cout << "Linux Button color changed to " << color << ".\n";
}

void LinuxButton::setFont(const std::string &font) {
  std::cout << "Linux Button font changed to " << font << ".\n";
}

void LinuxButton::setSize(int width, int height) {
  std::cout << "Linux Button size changed to " << width << "x" << height
            << ".\n";
}

void LinuxButton::setBorder(int border) {
  std::cout << "Linux Button border changed to " << border << ".\n";
}

void LinuxButton::setBorderRadius(int radius) {
  std::cout << "Linux Button border radius changed to " << radius << ".\n";
}
