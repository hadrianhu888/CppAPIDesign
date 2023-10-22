#include "LinuxButton.h"
#include <iostream>

void LinuxButton::click() { std::cout << "Linux Button clicked.\n"; }

void LinuxCheckBox::check() { std::cout << "Linux CheckBox checked.\n"; }

std::unique_ptr<Button> LinuxFactory::createButton() {
  return std::make_unique<LinuxButton>();
}

std::unique_ptr<CheckBox> LinuxFactory::createCheckBox() {
  return std::make_unique<LinuxCheckBox>();
}

std::unique_ptr<GUIFactory> createFactory(OSType type) {
  switch (type) {
  case OSType::Windows:
    return std::make_unique<WindowsFactory>();
  case OSType::Linux:
    return std::make_unique<LinuxFactory>();
  default:
    return nullptr;
  }
}

