#ifndef

#include "Button.h"
#include <iostream>
#include <memory>

class LinuxButton : public Button {
public:
  void click() override;
};
