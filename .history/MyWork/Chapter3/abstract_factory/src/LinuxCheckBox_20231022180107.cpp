#include "LinuxCheckBox.h"
#include <iostream>

void LinuxCheckBox::check() { std::cout << "Linux CheckBox checked.\n"; }

void LinuxCheckBox::paint() { std::cout << "Linux CheckBox painted.\n"; }

void LinuxCheckBox::setColor(const std::string &color) {
  
