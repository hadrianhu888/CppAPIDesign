#include "WindowsFactory.h"
#include "WindowsButton.h"
#include "WindowsCheckBox.h"
#include <memory>

std::unique_ptr<CheckBox> WindowsFactory::createCheckBox() {
  return std::make_unique<WindowsCheckBox>();
}

