#include "WindowsButton.h"
#include <iostream>

void WindowsButton::click() { std::cout << "Windows Button clicked.\n"; }

void WindowsButton::paint() { std::cout << "Windows Button painted.\n"; }

void WindowsButton::setColor(const std::string &color) {
  std::cout << "Windows Button color changed to " << color << ".\n";
}

void WindowsButton::setFont(const std::string &font) {
  std::cout << "Windows Button font changed to " << font << ".\n";
}

void WindowsButton::setText(const std::string &text) {
  std::cout << "Windows Button text changed to " << text << ".\n";
}

void WindowsButton::setSize(int size) {
  std::cout << "Windows Button size changed to " << size << ".\n";
}

void WindowsButton::setLocation(int x, int y) {
  std::cout << "Windows Button location changed to (" << x << ", " << y << ").\n";
}

