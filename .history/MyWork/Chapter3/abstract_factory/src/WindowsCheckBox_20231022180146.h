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
  void setColor(const std::string &color) override;
  void setSize(int size) override;
  void setLocation(int x, int y) override;
  void createCheckBox() override;
};
