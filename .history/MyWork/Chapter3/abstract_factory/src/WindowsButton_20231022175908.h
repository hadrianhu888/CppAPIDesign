#pragma once
#include "Button.h"

class WindowsButton : public Button {
public:
  void click() override;
  void paint() override;
  void setText(const std::string &text) override;
  void setFont(const std::string &font) override;
  void setColor(const std::string &color) override;
  void setSize(int size) override;
  
};
