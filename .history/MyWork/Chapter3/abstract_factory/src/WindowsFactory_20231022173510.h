#pragma once
#include "GUIFactory.h"

class WindowsFactory : public GUIFactory {
public:
  std::unique_ptr<Button> createButton() override;
  std::unique_ptr<CheckBox> createCheckBox() override;
};
