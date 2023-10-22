#include "WindowsCheckBox.h"
#include <iostream>

void WindowsCheckBox::check() { std::cout << "Windows CheckBox checked.\n"; }

void WindowsCheckBox::paint() { std::cout << "Windows CheckBox painted.\n"; }

void WindowsCheckBox::setColor(const std::string &color) {
  std::cout << "Windows CheckBox color changed to " << color << ".\n";
}

void WindowsCheckBox::setFont(const std::string &font) {
  std::cout << "Windows CheckBox font changed to " << font << ".\n";
}

void WindowsCheckBox::setText(const std::string &text) {
  std::cout << "Windows CheckBox text changed to " << text << ".\n";
}

void WindowsCheckBox::setSize(int size) {
  std::cout << "Windows CheckBox size changed to " << size << ".\n";
}

void WindowsCheckBox::setLocation(int x, int y) {
  std::cout << "Windows CheckBox location changed to (" << x << ", " << y
            << ").\n";
}
