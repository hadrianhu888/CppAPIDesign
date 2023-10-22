#ifndef LINUX

#include "Button.h"
#include <iostream>
#include <memory>

class LinuxButton : public Button {
public:
  void click() override;
};

#endif // BUTTON_H_
