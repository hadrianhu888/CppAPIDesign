#pragma once
#include "Button.h"
#include <memory>


class LinuxButton : public Button {
public:
  void click() override;
};
