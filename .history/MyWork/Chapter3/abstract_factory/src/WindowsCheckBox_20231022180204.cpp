#include "WindowsCheckBox.h"
#include <iostream>

void WindowsCheckBox::check() { std::cout << "Windows CheckBox checked.\n"; }

void WindowsCheckBox::paint() { std::cout << "Windows CheckBox painted.\n"; }

void WindowsCheckBox::setColor(const std::string &color) {
  std::cout << "Windows CheckBox color changed to " << color << ".\n";
}

