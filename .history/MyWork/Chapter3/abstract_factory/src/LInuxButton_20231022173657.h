#ifndef BUTTON_H_
#define BUTTON_H_

#include "Button.h"
#include <iostream>
#include <memory>

class LinuxButton : public Button {
public:
  void click() override;
};

#endif // BUTTON_H_
