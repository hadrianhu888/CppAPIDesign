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

void LinuxButton::setText(const std::string &text) {
  std::cout << "Linux Button text changed to " << text << ".\n";
}

void LinuxButton::setFont(const std::string &font) {
  std::cout << "Linux Button font changed to " << font << ".\n";
}

void LinuxButton::setColor(const std::string &color) {
  std::cout << "Linux Button color changed to " << color << ".\n";
}

void LinuxButton::setSize(int size) {
  std::cout << "Linux Button size changed to " << size << ".\n";
}

void setLocation(int x, int y) {
  
}
void createButton() override;
