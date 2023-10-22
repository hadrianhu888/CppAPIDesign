#include "Button.h"
#include "CheckBox.h"
#include "GUIFactory.h"
#include "LinuxFactory.h"
#include "WindowsFactory.h"
#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<GUIFactory> factory;
  factory = std::make_unique<WindowsFactory>();

  auto button = factory->createButton();
  auto checkBox = factory->createCheckBox();

  button->click();
  checkBox->check();

  return 0;
}
