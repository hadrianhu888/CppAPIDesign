#pragma once
#include "Button.h"
#include 

class LinuxButton : public Button {
public:
  void click() override;
};
