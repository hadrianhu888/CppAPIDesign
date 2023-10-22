#ifndef BUTTON_H_
#define BUTTON_H_

#ifndef WINDOWS_BUTTON_H_
#define WINDOWS_BUTTON_H_

#include "button.h"
#include <iostream>

class WindowsButton : public Button {
public:
  void paint() { std::cout << "Windows button" << std::endl; }
};

#endif // WINDOWS_BUTTON_H_

#endif // BUTTON_H_