#include "LinuxButton.h"
#include <iostream>

void LinuxButton::click() { std::cout << "Linux Button clicked.\n"; }

void LinuxCheckBox::check() { std::cout << "Linux CheckBox checked.\n"; }

std::unique_ptr<Button> LinuxFactory::createButton() {
  return std::make_unique<LinuxButton>();
}

