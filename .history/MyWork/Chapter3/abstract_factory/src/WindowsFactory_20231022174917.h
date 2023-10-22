#ifndef WINDOWS_BUTTON_H_
#define WINDOWS_BUTTON_H_

#include "GUIFactory.h"

class WindowsFactory : public GUIFactory {
public:
  std::unique_ptr<Button> createButton() override;
  std::unique_ptr<CheckBox> createCheckBox() override;
};

#endif // WINDOWS_BUTTON_H_