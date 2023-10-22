#include "LinuxFactory.h"
#include "LinuxCheckBox.h"
#include <memory>

std::unique_ptr<Button> LinuxFactory::createButton() {
  return std::make_unique<LinuxButton>();
}

std::unique_ptr<CheckBox> LinuxFactory::createCheckBox() {
  return std::make_unique<LinuxCheckBox>();
}
