#pragma once
#include "CheckBox.h"

class LinuxCheckBox : public CheckBox {
public:
  void check() override;
  ~LinuxCheckBox() override = default;
  void paint() override;
  void setText(const std::string &text) override;
  void setFont(const std::string &font) override;
  void setColor(const std::string &color) override;
  
};