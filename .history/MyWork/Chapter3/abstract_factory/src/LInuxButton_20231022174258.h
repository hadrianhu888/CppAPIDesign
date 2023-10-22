#ifndef LINUX_BUTTON_H_
#define LINUX_BUTTON_H_

#include "Button.h"
#include <iostream>
#include <memory>

class LinuxButton : public Button {
public:
  void click() override;
  void paint() override;
  void setText(const std::string &text) override;
  void setFont(const std::string &font) override;
  
};

#endif // LINUX_BUTTON_H_
