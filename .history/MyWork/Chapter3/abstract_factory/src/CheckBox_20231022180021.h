#pragma once

#include "Button.h"

class CheckBox {
public:
  virtual void check() = 0;
  virtual ~CheckBox() = default;
  virtual void paint() = 0;
  virtual void setText(const std::string &text) = 0;
  
};
