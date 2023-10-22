#pragma once

#include "Button.h"

class CheckBox {
public:
  virtual void check() = 0;
  virtual ~CheckBox() = default;
  virtual void paint() = 0;
  virtual void setText(const std::string &text) = 0;
  virtual void setFont(const std::string &font) = 0;
  virtual void setColor(const std::string &color) = 0;
  virtual void setSize(int size) = 0;
  virtual void setLocation(int x, int y) = 0;
  virtual void createCheckBox() = 0;
};
