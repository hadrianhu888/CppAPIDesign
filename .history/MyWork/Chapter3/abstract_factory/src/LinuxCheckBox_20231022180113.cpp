#include "LinuxCheckBox.h"
#include <iostream>

void LinuxCheckBox::check() { std::cout << "Linux CheckBox checked.\n"; }

void LinuxCheckBox::paint() { std::cout << "Linux CheckBox painted.\n"; }

void LinuxCheckBox::setColor(const std::string &color) {
  std::cout << "Linux CheckBox color changed to " << color << ".\n";
}

void LinuxCheckBox::setFont(const std::string &font) {
  std::cout << "Linux CheckBox font changed to " << font << ".\n";
}


