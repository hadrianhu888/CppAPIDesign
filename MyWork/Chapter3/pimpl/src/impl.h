/**
 * @file impl.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _IMPL_H_
#define _IMPL_H_

#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>

class impl {
public:
  std::chrono::time_point<std::chrono::system_clock> m_start;
  std::chrono::time_point<std::chrono::system_clock> m_stop;
  std::string m_name;
  std::string m_description;
  std::mutex m_mutex;
  void start();
  void stop();
  explicit impl(const std::string &name, const std::string &description,
                const std::chrono::milliseconds &duration);
};

#endif /* _IMPL_H_ */