#pragma once
#include "CheckBox.h"

class LinuxCheckBox : public CheckBox {
public:
  void check() override;
  ~LinuxCheckBox() override = default;
  
};
