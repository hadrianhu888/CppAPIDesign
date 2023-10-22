#pragma once
#include "Button.h"
#include "CheckBox.h"
#include <memory>

class GUIFactory {
public:
  virtual std::unique_ptr<Button> createButton() = 0;
  virtual std::unique_ptr<CheckBox> createCheckBox() = 0;
};
