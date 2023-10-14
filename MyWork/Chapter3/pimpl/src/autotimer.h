/**
 * @file autotimer.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _AUTO_TIMER_H_
#define _AUTO_TIMER_H_

#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>

#include "impl.h"

class AutoTimer {
private:
  class impl;
  impl *pimpl;

public:
  bool m_running;
  std::string m_name;
  std::chrono::time_point<std::chrono::system_clock> m_start;
  explicit AutoTimer(const std::chrono::milliseconds &duration);
  explicit AutoTimer(const std::string &name,
                     const std::chrono::milliseconds &duration);
  explicit AutoTimer(const std::string &name, const std::string &description,
                     const std::chrono::milliseconds &duration);
  AutoTimer();
  ~AutoTimer();
  void start();
  void stop();
  explicit AutoTimer(const std::string &name);
};

#endif /* _AUTO_TIMER_H_ */