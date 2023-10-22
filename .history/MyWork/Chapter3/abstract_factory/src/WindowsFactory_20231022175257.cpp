#include "LinuxButton.h"
#include "LinuxCheckBox.h"
#include "LinuxFactory.h"
#include <memory>

std::unique_ptr<Button> LinuxFactory::createButton() {
  return std::make_unique<LinuxButton>();
}

std::unique_ptr<CheckBox> LinuxFactory::createCheckBox() {
  return std::make_unique<LinuxCheckBox>();
}
