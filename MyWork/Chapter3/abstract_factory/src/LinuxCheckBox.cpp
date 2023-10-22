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

void LinuxCheckBox::setText(const std::string &text) {
  std::cout << "Linux CheckBox text changed to " << text << ".\n";
}

void LinuxCheckBox::setSize(int size) {
  std::cout << "Linux CheckBox size changed to " << size << ".\n";
}

void LinuxCheckBox::setLocation(int x, int y) {
  std::cout << "Linux CheckBox location changed to (" << x << ", " << y
            << ").\n";
}

void LinuxCheckBox::createCheckBox() {
  std::cout << "Linux CheckBox created.\n";
}
