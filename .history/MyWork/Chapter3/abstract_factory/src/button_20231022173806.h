/**
 * @file button.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <iostream>

class Button {
public:
  virtual void paint() = 0;
  virtual ~Button() {}
  virtual void click() = 0;
  
};

#endif // BUTTON_H_