#pragma once
#include "Button.h"
#include "CheckBox.h"

class WindowsCheckBox : public CheckBox {
public:
  void check() override;
  ~WindowsCheckBox() override = default;
  void paint() override;
  void setText(const std::string &text) override;
  void setFont(const std::string &font) override;
  
};
