/**
 * @file MySlot.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MYSLOT_H
#define MYSLOT_H

#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class MySlot {
public:
  static const string SIGNAL_EXIT;
  static const string SIGNAL_RELOAD;
  MySlot();
  ~MySlot();
  void operator()() const;
  void onSignalReceived(const string &signal);
  void onSignalReceived(const function<void()> &callback);
};

#endif // MYSLOT_H
