#pragma once
#include "Button.h"
#include "CheckBox.h"

class WindowsCheckBox : public CheckBox {
public:
  void check() override;
  ~WindowsCheckBox() override = default;
  void paint() override;
  
};
